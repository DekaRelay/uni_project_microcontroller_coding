#include "derivative.h"
#define BUFFER_SIZE 100
#include "serial.h"

int TDRE_BIT = 0x80;
extern char buffer[BUFFER_SIZE];
extern int buffer_index;
int dec;
int dVal;


void float_to_str(float n) {
 
 
 buffer_index = 0;  // Reset buffer_index
 
 n += 0.005;
 
 dVal = (int)n;
 dec = (int)(n * 100) % 100;
 
 buffer[buffer_index++] = (dec % 10) + '0';
 buffer[buffer_index++] = (dec / 10) + '0';
 buffer[buffer_index++] = '.';
 
 while (dVal > 0) {
 
  buffer[buffer_index++] = (dVal % 10) + '0';
  dVal /= 10;
 
 }
   
}


void Init_serial(void) {
 
 SCI1BDL = 0x9C;        // Set the baud rate to 9600
 SCI1BDH = 0x00;         
 SCI1CR1 = 0x4C;        // select 8 data bits, address mark wake-up 
 SCI1CR2 = 0x08;        // Enable transmitter
  
}


void send_serial(char *string) {
 
  int i;
  
  for (i = 0; i <= 80; i++){
    
    //if (SCI1SR1 & TDRE_BIT) {
    while(!(SCI1SR1 & TDRE_BIT));  
    SCI1DRL = string[i];
      
    //} 
   
  }
     
}

void send_char_serial(char character){
  
  while(!(SCI1SR1 & TDRE_BIT));
  SCI1DRL = character; 
  
}