#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */


void set_ADC(void);
void set_LEDs(void);
int msb(int);
void delay(void);



void main(void) {
  /* put your own code here */
  //initialise all variables and array to translate values to display on the 7 seg
  int seg_table[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F };
  int value = 0;
  int value2 = 0;
  int input;
  
  set_LEDs();
  set_ADC();
  

	EnableInterrupts;
	
  for(;;){

    //check if theres new input 
    if(ATD1STAT0 & 0x80){
  
      //do a 10bit atd conversion so that it can read up to 16 bit words at once
      input = ATD1DR0L;
      
      //input = ATD1DR1L
      
      //input = ATD1DR2L
    
      //reset the values
      value = 0;
      value2 = 0;
    
      //converting hex number to value of most significant bits
      while(input>=51){
      
        input = input - 51;
        value = value + 1;
      }
    
    
      //converting hex number to value of least significant bits
      while(input>5){
      
        input = input - 5;
        value2 = value2 + 1;
      }
    }
  
    //turning on the 7 seg display
    PTP = 0x0B;
  
    //output value to port b
    PORTB = seg_table[value2];
  
    //delay();
  
  
    //repeat for most significant bits
    PTP = 0x0D;
  
    //output value to port b, 0x80=decimal point is added
    //so the value displayed will have decimal place
    PORTB = 0x80 + seg_table[value];
  
    //delay();  
    
  }

}

//configure the LEDs
void set_LEDs(){
 
  //port p to output
  DDRP=0xFF;
  //port b as output
  DDRB=0xFF;
  //port j as output
  DDRJ=0xFF;
  //enable leds
  PTJ=0x00;
}

//configure adc
void set_ADC(){
  
  //ADPU and AFFC so staus register 1 doesnt have to re-read
  ATD1CTL2 = 0xC0;
  //ATD1CTL2 = 0x80;
  //1MHz = 16AD cycles
  //ATD1CTL4 = 0xEB;
  ATD1CTL4 = 0xEB;    
  //1 conversion no FIFO
  ATD1CTL3 = 0x08;
  //channel 7 through bits 0-2 set as 111
  ATD1CTL5 = 0xA7;
  //ATD1CTL5 = 0x87;
}


void delay(){

  TSCR2 = 0x07;   //reset register
  
  TSCR1 = 0x90; //set TFFCA flag and timer 
  
  
  TIOS = 0x01;    //Set all channels to output compare mode 
  
  
  //Wait for the falling edge to be signalled in the appropriate interrupt flag
  TC0 = TCNT + 188; //188 = 24MHz/128 * 1ms  
       
  while(!(TFLG1 & 0x01));

}



