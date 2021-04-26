#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include "timers.h"
#include "measure.h"
#include "serial.h"
#include "ascii_output.h"
#define BUFFER_SIZE 100


long measure_double (int type);   /* Unknown error where the code doesn't recognize if declared in headerfile*/


int overflow = 0;
char buffer[BUFFER_SIZE];
int buffer_index;

void main(void) {
  /* put your own code here */

    
    // Time measurement arrays
    float time[4][6];

    int i;
    float prescaler = 41.6*0.001;  // microseconds
   
 
 	EnableInterrupts;
	
	
	//------------------------ Exercise 1 ----------------------------   
  // Initiate timer
  Init_Timer();


  // Measure time for arithmatics 
  for (i = 0; i < 6; i++){
    time[0][i] = measure_int(i) * prescaler;
    time[1][i] = measure_long(i) * prescaler;
    time[2][i] = measure_32f(i) * prescaler;
    time[3][i] = measure_double(i) * prescaler;   
  }


  // Enter function to initialise serial
  Init_serial();
  
  // Convert to table format
  ascii_table(time);   // Convert float into table layout
  
  // Send to serial 



  for(;;) {
    _FEED_COP(); /* feeds the dog */
  } /* loop forever */
  /* please make sure that you never leave main */
}