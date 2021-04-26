// Macro
#include <hidef.h>           // common defines and macros 
#include "derivative.h"      // derivative-specific definitions
//#define INPUT_OVERFLOW 1000  // allocated memory for serial input
#include "serial_int.h"


// Global variables
unsigned char inputs[INPUT_OVERFLOW];    // variables for buffer
unsigned int input_index = 0;

unsigned int RDRF_BIT = 0x20;            // bit masks for Serial recieve and transmit
extern int TDRE_BIT;

unsigned int num_sent = 0;               // variables to transmit characters to appropriate terminal
unsigned int received_0 = 0;
unsigned int received_1 = 0;


// Interupt - serial_1_ISR
// Interupt to store user input from serial 1
// Tigger: user entered inputs through terminal
// Function: stores user inputed characters into an input array
#pragma CODE_SEG __NEAR_SEG NON_BANKED
__interrupt void serial_1_ISR(void) {
  
  while(!(SCI1SR1 & RDRF_BIT));     // wait for RDRF to be set
  inputs[input_index++] = SCI1DRL;    // store the character recieved in input array
  
  // set recieved_1 to indicate that the current character is coming from SCI0
  received_1 = 1;
  
  // if inputs has reached the end of allocated memory, reset the input index
  if (input_index >= INPUT_OVERFLOW){
    input_index = 0;
  }
  
}


// Interupt - serial_0_ISR
// Interupt to store user input from serial 0
// Tigger: user entered inputs through terminal
// Function: stores user inputed characters into an input array
#pragma CODE_SEG __NEAR_SEG NON_BANKED
__interrupt void serial_0_ISR(void) {
  
  while(!(SCI0SR1 & RDRF_BIT));     // wait for RDRF to be set
  inputs[input_index++] = SCI0DRL;    // store the character recieved in input array
  
  // set recieved_0 to indicate that the current character is coming from SCI0
  received_0 = 1;
  
  // if inputs has reached the end of allocated memory, reset the input index
  if (input_index >= INPUT_OVERFLOW){
    input_index = 0;
  }
  
}


// Function to configure set up of serial I/O
void Init_serial_struct(struct serial_parameters *set_serial){
  
 // Enabling serial port 0
 SCI0BDL = set_serial->baud_rate_L;        
 SCI0BDH = set_serial->baud_rate_H;         
 SCI0CR1 = set_serial->CR1;                 
 SCI0CR2 = set_serial->CR2;        
  
 // Enabling serial port 1
 SCI1BDL = set_serial->baud_rate_L;        
 SCI1BDH = set_serial->baud_rate_H;         
 SCI1CR1 = set_serial->CR1;        
 SCI1CR2 = set_serial->CR2;        

}


// Function to set up set_serial struct
struct serial_parameters struct_init(void) {
 
 struct serial_parameters set_serial;
  
 set_serial.baud_rate_L = 0x9C;     // Set the baud rate to 9600
 set_serial.baud_rate_H = 0x00;
 set_serial.CR1 = 0x4C;             // select 8 data bits, address mark wake-up 
 set_serial.CR2 = 0x2C;             // Enable transmitter and reciever, enable receiver interrupt
                                    
 return set_serial; 
  
}


// Function to sent each character back to the port it came from 
void send_serial_struct(void) {
  
  if ((num_sent != input_index) && (SCI1SR1 & TDRE_BIT)){    // Check if all inputed characters have been sent and wait for the TDRE to be clear
  
    // send character to the appropriate terminal
    
    if (received_0) {
      SCI0DRL = inputs[num_sent++];    // write the character from the inputs array to SCI0
    } 
    else if (received_1) {
      SCI1DRL = inputs[num_sent++];    // write the character from the inputs array to serial
    }
    
    // set recieved variables to zero so they can be used again
    
    received_1 = 0;
    received_0 = 0;
      
  
  }
  
}