#include "t_data.h"
#include "derivative.h"
#include <math.h>


int count = 0;          // global variable for timer counts            

int* generate_time (int err){

  static int new_time[24];
  
  unsigned start_time, end_time;  // Start and end time
  unsigned start_count, end_count;
  unsigned empty_time; 

  volatile int a, b, c;           // integer calculations
  volatile long la, lb, lc;
  volatile float fa, fb, fc;
  volatile double da, db, dc;

  b = 10;
  c = 7;
  lb = 1000;
  lc = 500;
  fb = 15.25;
  fc = 3.14;
  db = 15.2564565;
  dc = 3.141592;
  

  //------------------ Empty cycle ----------------------
  start_count = count;
  start_time = TCNT;
  
  // Empty process time count
  
  end_time = TCNT; 
  end_count = count;
  
  start_time = start_time + 0xFF*start_count;
  end_time = end_time + 0xFF*end_count;
  
  empty_time = end_time - start_time;


  //-------------------------- Integer ---------------------------- 
  // (1) Addition
  start_count = count;
  start_time = TCNT;
  
  a = b + c;
  
  end_time = TCNT; 
  end_count = count;
  
  start_time = start_time + 0xFF*start_count;
  end_time = end_time + 0xFF*end_count;
  
  
  new_time[0] = end_time - start_time - empty_time;
  
    
  // (2) Multiply
  start_count = count;
  start_time = TCNT;
  
  a = b * c;
  
  end_time = TCNT; 
  end_count = count;
  
  start_time = start_time + 0xFF*start_count;
  end_time = end_time + 0xFF*end_count;
  
  
  new_time[1] = end_time - start_time - empty_time;
  
  
  // (3) Division
  start_count = count;
  start_time = TCNT;
  
  a = b / c;
  
  end_time = TCNT; 
  end_count = count;
  
  start_time = start_time + 0xFF*start_count;
  end_time = end_time + 0xFF*end_count;
  
  
  new_time[2] = end_time - start_time - empty_time;
  
  
  // (4) Square root
  start_count = count;
  start_time = TCNT;
  
  a = sqrt(b);
  
  end_time = TCNT; 
  end_count = count;
  
  start_time = start_time + 0xFF*start_count;
  end_time = end_time + 0xFF*end_count;
  
  
  new_time[3] = end_time - start_time - empty_time;
  
  
  // (5) Sine
  start_count = count;
  start_time = TCNT;
  
  a = sin(b);
  
  end_time = TCNT; 
  end_count = count;
  
  start_time = start_time + 0xFF*start_count;
  end_time = end_time + 0xFF*end_count;
  
  
  new_time[4] = end_time - start_time - empty_time;
  
   
  // (6) Cosine
  start_count = count;
  start_time = TCNT;
  
  a = cos(b);
  
  end_time = TCNT; 
  end_count = count;
  
  start_time = start_time + 0xFF*start_count;
  end_time = end_time + 0xFF*end_count;
  
  
  new_time[5] = end_time - start_time - empty_time; 
  
  
  //-------------------------- Long ---------------------------
  // (1) Addition
  start_count = count;
  start_time = TCNT;
  
  la = lb + lc;
  
  end_time = TCNT; 
  end_count = count;
  
  start_time = start_time + 0xFF*start_count;
  end_time = end_time + 0xFF*end_count;
  
  
  new_time[6] = end_time - start_time - empty_time;
  
    
  // (2) Multiply
  start_count = count;
  start_time = TCNT;
  
  la = lb * lc;
  
  end_time = TCNT; 
  end_count = count;
  
  start_time = start_time + 0xFF*start_count;
  end_time = end_time + 0xFF*end_count;
  
  
  new_time[7] = end_time - start_time - empty_time;
  
  
  // (3) Division
  start_count = count;
  start_time = TCNT;
  
  la = lb / lc;
  
  end_time = TCNT; 
  end_count = count;
  
  start_time = start_time + 0xFF*start_count;
  end_time = end_time + 0xFF*end_count;
  
  
  new_time[8] = end_time - start_time - empty_time;
  
  
  // (4) Square root
  start_count = count;
  start_time = TCNT;
  
  la = sqrt(lb);
  
  end_time = TCNT; 
  end_count = count;
  
  start_time = start_time + 0xFF*start_count;
  end_time = end_time + 0xFF*end_count;
  
  
  new_time[9] = end_time - start_time - empty_time;
  
  
  // (5) Sine
  start_count = count;
  start_time = TCNT;
  
  la = sin(lb);
  
  end_time = TCNT; 
  end_count = count;
  
  start_time = start_time + 0xFF*start_count;
  end_time = end_time + 0xFF*end_count;
  
  
  new_time[10] = end_time - start_time - empty_time;
  
   
  // (6) Cosine
  start_count = count;
  start_time = TCNT;
  
  la = cos(lb);
  
  end_time = TCNT; 
  end_count = count;
  
  start_time = start_time + 0xFF*start_count;
  end_time = end_time + 0xFF*end_count;
  
  
  new_time[11] = end_time - start_time - empty_time;
  
  //-------------------------- Float 32 bit ---------------------------
  // (1) Addition
  start_count = count;
  start_time = TCNT;
  
  fa = fb + fc;
  
  end_time = TCNT; 
  end_count = count;
  
  start_time = start_time + 0xFF*start_count;
  end_time = end_time + 0xFF*end_count;
  
  
  new_time[12] = end_time - start_time - empty_time;
  
    
  // (2) Multiply
  start_count = count;
  start_time = TCNT;
  
  fa = fb * fc;
  
  end_time = TCNT; 
  end_count = count;
  
  start_time = start_time + 0xFF*start_count;
  end_time = end_time + 0xFF*end_count;
  
  
  new_time[13] = end_time - start_time - empty_time;
  
  
  // (3) Division
  start_count = count;
  start_time = TCNT;
  
  fa = fb / fc;
  
  end_time = TCNT; 
  end_count = count;
  
  start_time = start_time + 0xFF*start_count;
  end_time = end_time + 0xFF*end_count;
  
  
  new_time[14] = end_time - start_time - empty_time;
  
  
  // (4) Square root
  start_count = count;
  start_time = TCNT;
  
  fa = sqrt(fb);
  
  end_time = TCNT; 
  end_count = count;
  
  start_time = start_time + 0xFF*start_count;
  end_time = end_time + 0xFF*end_count;
  
  
  new_time[15] = end_time - start_time - empty_time;
  
  
  // (5) Sine
  start_count = count;
  start_time = TCNT;
  
  fa = sin(fb);
  
  end_time = TCNT; 
  end_count = count;
  
  start_time = start_time + 0xFF*start_count;
  end_time = end_time + 0xFF*end_count;
  
  
  new_time[16] = end_time - start_time - empty_time;
  
   
  // (6) Cosine
  start_count = count;
  start_time = TCNT;
  
  fa = cos(fb);
  
  end_time = TCNT; 
  end_count = count;
  
  start_time = start_time + 0xFF*start_count;
  end_time = end_time + 0xFF*end_count;
  
  
  new_time[17] = end_time - start_time - empty_time;
  
  //-------------------------- Float 64 bit ---------------------------
  // (1) Addition
  start_count = count;
  start_time = TCNT;
  
  da = db + dc;
  
  end_time = TCNT; 
  end_count = count;
  
  start_time = start_time + 0xFF*start_count;
  end_time = end_time + 0xFF*end_count;
  
  
  new_time[18] = end_time - start_time - empty_time;
  
    
  // (2) Multiply
  start_count = count;
  start_time = TCNT;
  
  da = db * dc;
  
  end_time = TCNT; 
  end_count = count;
  
  start_time = start_time + 0xFF*start_count;
  end_time = end_time + 0xFF*end_count;
  
  
  new_time[19] = end_time - start_time - empty_time;
  
  
  // (3) Division
  start_count = count;
  start_time = TCNT;
  
  da = db / dc;
  
  end_time = TCNT; 
  end_count = count;
  
  start_time = start_time + 0xFF*start_count;
  end_time = end_time + 0xFF*end_count;
  
  
  new_time[20] = end_time - start_time - empty_time;
  
  
  // (4) Square root
  start_count = count;
  start_time = TCNT;
  
  da = sqrt(db);
  
  end_time = TCNT; 
  end_count = count;
  
  start_time = start_time + 0xFF*start_count;
  end_time = end_time + 0xFF*end_count;
  
  
  new_time[21] = end_time - start_time - empty_time;
  
  
  // (5) Sine
  start_count = count;
  start_time = TCNT;
  
  da = sin(db);
  
  end_time = TCNT; 
  end_count = count;
  
  start_time = start_time + 0xFF*start_count;
  end_time = end_time + 0xFF*end_count;
  
  
  new_time[22] = end_time - start_time - empty_time;
  
   
  // (6) Cosine
  start_count = count;
  start_time = TCNT;
  
  da = cos(db);
  
  end_time = TCNT; 
  end_count = count;
  
  start_time = start_time + 0xFF*start_count;
  end_time = end_time + 0xFF*end_count;
  
  
  new_time[23] = end_time - start_time - empty_time;
  
  
  
  
  
  
  return new_time;


  
}