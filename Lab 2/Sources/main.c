#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include "timers.h"
#include "measure.h"


int overflow = 0;

void main(void) {
  /* put your own code here */
  

    int a = 0;
    long tick_int[6];
    long tick_long[6];
    long tick_32f[6];
    long tick_64f[6];
    int i;
 
 
 	EnableInterrupts;
	   
  // Initiate timer
  Init_Timer();


  // Measure time for arithmatics 
  for (i = 0; i < 6; i++){
    tick_int[i] = measure_int(i);
    tick_long[i] = measure_long(i);
    //tick_32f[i] = measure_32f(i);
    //tick_64f[i] = measure_64f(i);
 
  }


	

  for(;;) {
    _FEED_COP(); /* feeds the dog */
  } /* loop forever */
  /* please make sure that you never leave main */
}
