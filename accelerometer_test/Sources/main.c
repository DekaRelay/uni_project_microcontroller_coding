#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */

int input[3];

void init_ADC(void);

void main(void) {
  /* put your own code here */
  
  init_ADC();


	EnableInterrupts;


  for(;;) {
  
    ATD1CTL5 = 0x87;
    
    while (!(ATD1STAT0 & 0x80));
    
    input[0] = ATD1DR0L;

    input[1] = ATD1DR1L;
    
    input[2] = ATD1DR2L;  
  
    _FEED_COP(); /* feeds the dog */
  } 
  
}


void init_ADC(void) {
  
  ATD1CTL2 = 0b10000000;  // Turn on ADC,..No Interrupt	
  ATD1CTL3 = 0b10011000;  // three conversion, no FIFO
  ATD1CTL4 = 0xEB;        // 8-bit resolu, 16-clock for 2nd phase,
                          // prescaler of 24 for Conversion Freq=1MHz                   
  
}