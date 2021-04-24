#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include "timers.h"
#include "measure.h"

int overflow = 0;

void main(void) {
  /* put your own code here */

    
    // Time measurement arrays
    float time[3][6];

    int i;
    float prescaler = 41.6*0.001;  // microseconds
 
 
 	EnableInterrupts;
	   
  // Initiate timer
  Init_Timer();


  // Measure time for arithmatics 
  for (i = 0; i < 6; i++){
    time[0][i] = measure_int(i) * prescaler;
    time[1][i] = measure_long(i) * prescaler;
    time[2][i] = measure_32f(i) * prescaler;   
  }



  for(;;) {
    _FEED_COP(); /* feeds the dog */
  } /* loop forever */
  /* please make sure that you never leave main */
}
