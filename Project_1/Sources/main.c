#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#define BUFFER_SIZE 100

float time;
int TDRE_BIT = 0x80;
char buffer[BUFFER_SIZE];
int buffer_index = 0;
int dec;
int dVal;
char check;

void Init_serial(void);
void send_serial(void);
void float_to_str(float);


void main(void) {
  
  Init_serial();       // Enter function to initialise serial
  
  time = 245.95985;
  
  float_to_str(time);  // convert time into a string and store in buffer array
  
	EnableInterrupts;

  send_serial();

  for(;;) {
       
    _FEED_COP(); /* feeds the dog */
    
  } 
}


void float_to_str(float n) {
 
 //n += 0.0005;
 
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


void send_serial(void) {
 
  int i;
  
  for (i = buffer_index-1; i >= 0; i--){
    
    while(!(SCI1SR1 & TDRE_BIT)); 
      
    SCI1DRL = buffer[i]; 
   
  }
      
}