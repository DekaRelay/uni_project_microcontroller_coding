#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include <math.h>
#include "timers.h"
#include "t_data.h"


void main(void) {
  /* put your own code here */
 
  //  Variable initilisations

  
  
  float time[4][6];            // Result times
  int* time_loc;
  int i;
  float prescaler;
  
  
  // Initiate timer
  Init_TC7();
  
  // Measure time for each arithmatic calculations
  time_loc = generate_time(0);

  // Resave into a matrix, Multiply by prescaler (1)
  prescaler = 41.6;         // nanoseconds
  
  for ( i = 0; i < 6; i++ ) {
      time[0][i] = *(time_loc + i) * prescaler;
      time[1][i] = *(time_loc + i + 6) * prescaler;
      time[2][i] = *(time_loc + i + 12) * prescaler;
      time[3][i] = *(time_loc + i + 18) * prescaler;     
  }
 
  
  
	EnableInterrupts;


  for(;;) {
    _FEED_COP(); /* feeds the dog */
  } /* loop forever */
  /* please make sure that you never leave main */
}
