//Displaying ATD0 channel 7 (POT) on LEDs of PORTB in C Language for Dragon12+ Trainer Board 
//with HCS12 Serial Monitor Program installed. This code is for CodeWarrior IDE
//Modified from Program 13-1C of HCS12 book by Mazidi & Causey 
//In Dragon12+ PLL=48MHz. 48MHz/2=24MHz, Divivde by 24 to get 1MHz for conversion freq. 
//ATD0 channel 7 (AN07) is connected to VR2 Pot Trimer (above right side of breadboard)
//Change the POT to see the changes on LEDs of PORTB
 
#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */

void set_ADC(void);
void set_LEDs(void);
void delay(unsigned int);
void main(void) 
 {
  /* put your own code here */
  /* put your own code here */
  //initialise all variables and array to translate values to display on the 7 seg
    int seg_table[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F };
    int value = 0;
    int value2 = 0;
    int inputx;  
    int inputy; 
    int inputz;
    int difference;    

    set_LEDs();
    set_ADC();
      

	  EnableInterrupts; 
	  
	  
	  
    for(;;)
    {
    
      ATD1CTL5 = 0x87;    
      while (ATD1STAT0 & 0x80);
    
      //get x axis value
      inputx = ATD1DR0L;
      //get y axis value
      inputy = ATD1DR1L;
      //get z axis value
      inputz = ATD1DR2L;
      
      //check if x and y value are the same, if they are different
      //find the difference in the value
      while (inputx != inputy) {
       if (inputx > inputy){
        difference = inputx - inputy;
       }
       if (inputy > inputx){
        difference = inputy - inputx;
       }
      }
      
      //check if x and z value are the same, if they are different
      //find the difference in the value      
      while (inputx != inputz) {
       if (inputx > inputz){
        difference = inputx - inputz;
       }
       if (inputy > inputx){
        difference = inputz - inputx;
       }
      }   

      //reset the values
      value = 0;
      value2 = 0;
    
      //converting hex number to value of most significant bits
      while(difference>=50){
      
        difference = difference - 50;
        value = value + 1;
      }
    
    
      //converting hex number to value of least significant bits
      while(difference>5){
      
        difference = difference - 5;
        value2 = value2 + 1;
      }
    }
  
    //turning on the 7 seg display
    PTP = 0x0B;
  
    //output value to port b
    PORTB = seg_table[value2];
  
    delay(1);
  
  
    //repeat for most significant bits
    PTP = 0x0D;
  
    //output value to port b, 0x80=decimal point is added
    //so the value displayed will have decimal place
    PORTB = 0x80 + seg_table[value];
  
    //delay();  
    
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
  
  ATD1CTL2 = 0x80;     //Turn on ADC,..No Interrupt 	
  ATD1CTL3 = 0x08;  //one conversion, no FIFO
  ATD1CTL4 = 0xEB;  //8-bit resolu, 16-clock for 2nd phase,
                      //prescaler of 24 for Conversion Freq=1MHz 

  //ATD0CTL5 = 0xA7;

}

void delay(void){

  TSCR2 = 0x07;   //reset register
  
  TSCR1 = 0x90; //set TFFCA flag and timer 
  
  
  TIOS = 0x01;    //Set all channels to output compare mode 
  
  
  //Wait for the falling edge to be signalled in the appropriate interrupt flag
  TC0 = TCNT + 188; //188 = 24MHz/128 * 1ms  
       
  while(!(TFLG1 & 0x01));

}