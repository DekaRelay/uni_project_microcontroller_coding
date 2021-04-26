#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include "timers.h"
#include "measure.h"
#include "serial.h"
#include "ascii_output.h"
#define BUFFER_SIZE 100

int overflow = 0;
char buffer[BUFFER_SIZE];
int buffer_index;
char ascii_array[9][85];

void main(void) {
  /* put your own code here */

    
    // Time measurement arrays
    float time[3][6];

    int i, j;
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


  // Enter function to initialise serial
  Init_serial();
  
  ascii_table(time);
  for(i = 0 ; i<9 ; i++){
    
    send_serial(ascii_array[i]);
    send_char_serial(13);	
  
  }
  // Send measured floats to serial
  //for(i = 0; i < 3; i++){
    //for(j = 0; j < 6; j++){
      //float_to_str(time[i][j]); // Convert time into a string and store to buffer
    
      //send_serial();
    //}
  //}


  for(;;) {
    _FEED_COP(); /* feeds the dog */
  } /* loop forever */
  /* please make sure that you never leave main */
}
