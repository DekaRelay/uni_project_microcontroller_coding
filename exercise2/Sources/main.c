// Macro
#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#define INPUT_OVERFLOW 1000  // allocated memory for serial input


// Global variables
unsigned char inputs[INPUT_OVERFLOW];
unsigned int RDRF_BIT = 0x20;   
unsigned int TDRE_BIT = 0x80;
unsigned int input_index = 0;
unsigned int num_sent = 0;
unsigned int received_0 = 0;
unsigned int received_1 = 0;


// Declaration of functions to be used in program
void Init_serial(void);
void send_serial(void);  
  
void main(void) {
  
  Init_serial();       // Enter function to initialise serial interupt
	EnableInterrupts;     

  for(;;) {
    send_serial();      // Send characters from serial
  } 
  
}


// Interupt - serial_1_ISR
// Interupt to store user input from serial 1
// Tigger: user entered inputs through terminal
// Function: stores user inputed characters into an input array
__interrupt 21 void serial_1_ISR(void) {
  
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
__interrupt 20 void serial_0_ISR(void) {
  
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
void Init_serial(void){
  
 // Enabling serial port 0
 SCI0BDL = 0x9C;        // Set the baud rate to 9600
 SCI0BDH = 0x00;         
 SCI0CR1 = 0x4C;        // select 8 data bits, address mark wake-up 
 SCI0CR2 = 0x2C;        // Enable transmitter and reciever, enable receiver interrupt
  
 // Enabling serial port 1
 SCI1BDL = 0x9C;        // Set the baud rate to 9600
 SCI1BDH = 0x00;         
 SCI1CR1 = 0x4C;        // select 8 data bits, address mark wake-up 
 SCI1CR2 = 0x2C;        // Enable transmitter and reciever, enable receiver interrupt

}


// Function to sent each character back to the port it came from 
void send_serial(void) {
 
  // some logic to determine where the serial is going
  
  // Check if all inputed characters have been sent and wait for the TDRE to be clear
  if ((num_sent != input_index) && (SCI1SR1 & TDRE_BIT)){  
  
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