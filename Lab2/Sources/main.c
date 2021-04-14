#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include <math.h>
#include "timers.h"

int count;                        // global variable for timer counts

void main(void) {
  /* put your own code here */
 
  //  Variable initilisations
  volatile int a, b, c;           // integer calculations
  volatile long d, e, f;
  
  unsigned start_time, end_time;  // Start and end time
  unsigned start_count, end_count; 
  //unsigned time[4][7];            // Result times
  
  typedef struct {                // Struct for time data
    int add;
    int mult;
    int div;
    int sqrt;
    int sin;
    int cos;  
  }time;
  
  
  // Initialise each time structs  (integer, long, 32 & 64 bit floats)
  time t_int;
  time t_long;
  time t_32f;
  time t_64f;
  
  unsigned reps;

  // Initiate timer
  Init_TC7();


  
  // (1) Addition
  b = 8;
  c = 5;
  
  start_count = count;
  start_time = TCNT;
  
  a = b + c;
  
  end_time = TCNT; 
  end_count = count;
  
  start_time = start_time + 0xFF*start_count;
  end_time = end_time + 0xFF*end_count;
  
  
  t_int.add = end_time - start_time;
  
    
  // (2) Multiply
  start_count = count;
  start_time = TCNT;
  
  a = b * c;
  
  end_time = TCNT; 
  end_count = count;
  
  start_time = start_time + 0xFF*start_count;
  end_time = end_time + 0xFF*end_count;
  
  
  t_int.mult = end_time - start_time;
  
  
  // (3) Division
  start_count = count;
  start_time = TCNT;
  
  a = b / c;
  
  end_time = TCNT; 
  end_count = count;
  
  start_time = start_time + 0xFF*start_count;
  end_time = end_time + 0xFF*end_count;
  
  
  t_int.div = end_time - start_time;
  
  
  // (4) Square root
  start_count = count;
  start_time = TCNT;
  
  a = sqrt(b);
  
  end_time = TCNT; 
  end_count = count;
  
  start_time = start_time + 0xFF*start_count;
  end_time = end_time + 0xFF*end_count;
  
  
  t_int.sqrt = end_time - start_time;
  
  
  // (5) Sine
  start_count = count;
  start_time = TCNT;
  
  a = sin(b);
  
  end_time = TCNT; 
  end_count = count;
  
  start_time = start_time + 0xFF*start_count;
  end_time = end_time + 0xFF*end_count;
  
  
  t_int.sin = end_time - start_time;
  
   
  // (6) Cosine
  start_count = count;
  start_time = TCNT;
  
  a = cos(b);
  
  end_time = TCNT; 
  end_count = count;
  
  start_time = start_time + 0xFF*start_count;
  end_time = end_time + 0xFF*end_count;
  
  
  t_int.cos = end_time - start_time;  
  
  
	EnableInterrupts;


  for(;;) {
    _FEED_COP(); /* feeds the dog */
  } /* loop forever */
  /* please make sure that you never leave main */
}
