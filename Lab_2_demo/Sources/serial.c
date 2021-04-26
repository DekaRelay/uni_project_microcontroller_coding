#include "derivative.h"
#define BUFFER_SIZE 100
#include "serial.h"

extern int TDRE_BIT;
extern char buffer[BUFFER_SIZE];
extern int buffer_index;
int dec;
int dVal;


void float_to_str(float n) {
 
  // Reset buffer_index
 for(buffer_index = 0; buffer_index < BUFFER_SIZE; buffer_index++) {
    buffer[buffer_index] = 0;
 }

 buffer_index = 0;
 
 n += 0.005;                                        // Round to 2 decimal places
 
 dVal = (int)n;                                     // Takes integer part of float
 dec = (n - dVal)*100;                              // Takes the decimal parts upto 2 decimal places
 
 buffer[buffer_index++] = (dec % 10) + '0';         // Save second decimal place into buffer
 buffer[buffer_index++] = (dec / 10) + '0';         // Save first decimal place into buffer
 buffer[buffer_index++] = '.';
 
 if(dVal == 0) buffer[buffer_index++] = '0';        // If integer part is 0, save 0 instead of skipping

 while (dVal > 0) {                                 // Take each integer one by one and save to buffer
 
  buffer[buffer_index++] = (dVal % 10) + '0';       // Save the ASCII value of digits
  dVal /= 10;                                       // Move on to next digit
 
 }
   
}


// function to initialise serial ports
void Init_serial(void) {
 
 SCI1BDL = 0x9C;                                    // Set the baud rate to 9600
 SCI1BDH = 0x00;         
 SCI1CR1 = 0x4C;                                    // select 8 data bits, address mark wake-up 
 SCI1CR2 = 0x08;                                    // Enable transmitter
  
}


// function to send data to serial with polling
void send_serial(char *string) {
 
  int i;
  
  for (i = 0; i <= 80; i++){
    
    while(!(SCI1SR1 & TDRE_BIT));                   // Check the flag is enabled  
    SCI1DRL = string[i];                            // transmit to serial
   
  }
     
}

void send_char_serial(char character){
  
  while(!(SCI1SR1 & TDRE_BIT));
  SCI1DRL = character; 
  
}