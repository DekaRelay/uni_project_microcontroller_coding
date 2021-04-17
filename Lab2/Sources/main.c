#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include <math.h>
#include "timers.h"
#include "t_data.h"


void main(void) {
  /* put your own code here */
 
  //  Variable initilisations

  
  
  int time[4][6];            // Result times
  int* time_loc;
  int i;
  
  
  // Initiate timer
  Init_TC7();
  
  time_loc = generate_time(0);

  for ( i = 0; i < 6; i++ ) {
      time[0][i] = *(time_loc + i);
      time[1][i] = *(time_loc + i + 6);
      time[2][i] = *(time_loc + i + 12);
      time[3][i] = *(time_loc + i + 18);     
  }
 
 
  
	EnableInterrupts;


  for(;;) {
    _FEED_COP(); /* feeds the dog */
  } /* loop forever */
  /* please make sure that you never leave main */
}
