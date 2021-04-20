#include "measure.h"
#include "derivative.h"
#include <math.h>



// Integer time measurement
long measure_int (int type){

  extern int overflow;
  volatile long s_time;
  volatile long e_time;
  volatile long time;
  volatile long empty_time;
  volatile int a, b, c;
  b = 10;
  c = 8;
  
  // Measure 'empty' case
  s_time = TCNT + (65536)*overflow;
    
  // Empty case
      
  e_time = TCNT + (65536)*overflow;
      
  empty_time = e_time - s_time;
  
  
  // Select arithmatics
  switch(type){ 
    case 0: // Addition
    
      s_time = TCNT + (65536)*overflow;
    
      a = b + c;
      
      e_time = TCNT + (65536)*overflow;
      
      time = e_time - s_time;
      
      break;
      
    case 1: // Multiplication
    
      s_time = TCNT + (65536)*overflow;
    
      a = b * c;
      
      e_time = TCNT + (65536)*overflow;
      
      time = e_time - s_time;
      
      break;
      
    case 2: // Division
    
      s_time = TCNT + (65536)*overflow;
    
      a = b / c;
      
      e_time = TCNT + (65536)*overflow;
      
      time = e_time - s_time;
      
      break;
      
    case 3: // Square root
    
      s_time = TCNT + (65536)*overflow;
    
      a = sqrt(b);
      
      e_time = TCNT + (65536)*overflow;
      
      time = e_time - s_time;
      
      break;
      
    case 4: // Sine
    
      s_time = TCNT + (65536)*overflow;
    
      a = sin(b);
      
      e_time = TCNT + (65536)*overflow;
      
      time = e_time - s_time;
      
      break;
      
    case 5: // Cosine
    
      s_time = TCNT + (65536)*overflow;
    
      a = cos(b);
      
      e_time = TCNT + (65536)*overflow;
      
      time = e_time - s_time;
      
      break;
      
    default: 
      time = 0;
  }
  
  
  return time - empty_time;
}




//Long time measurment
long measure_long (int type){

  extern int overflow;
  volatile long s_time;
  volatile long e_time;
  volatile long time;
  volatile long empty_time;
  volatile long a, b, c;
  b = 1000000;
  c = 800000;
  
  // Measure 'empty' case
  s_time = TCNT + (65536)*overflow;
    
  // Empty case
      
  e_time = TCNT + (65536)*overflow;
      
  empty_time = e_time - s_time;
  
  
  // Select arithmatics
  switch(type){ 
    case 0: // Addition
    
      s_time = TCNT + (65536)*overflow;
    
      a = b + c;
      
      e_time = TCNT + (65536)*overflow;
      
      time = e_time - s_time;
      
      break;
      
    case 1: // Multiplication
    
      s_time = TCNT + (65536)*overflow;
    
      a = b * c;
      
      e_time = TCNT + (65536)*overflow;
      
      time = e_time - s_time;
      
      break;
      
    case 2: // Division
    
      s_time = TCNT + (65536)*overflow;
    
      a = b / c;
      
      e_time = TCNT + (65536)*overflow;
      
      time = e_time - s_time;
      
      break;
      
    case 3: // Square root
    
      s_time = TCNT + (65536)*overflow;
    
      a = sqrt(b);
      
      e_time = TCNT + (65536)*overflow;
      
      time = e_time - s_time;
      
      break;
      
    case 4: // Sine
    
      s_time = TCNT + (65536)*overflow;
    
      a = sin(b);
      
      e_time = TCNT + (65536)*overflow;
      
      time = e_time - s_time;
      
      break;
      
    case 5: // Cosine
    
      s_time = TCNT + (65536)*overflow;
    
      a = cos(b);
      
      e_time = TCNT + (65536)*overflow;
      
      time = e_time - s_time;
      
      break;
      
    default: 
      time = 0;
  }
  
  
  return time - empty_time;
} //*/


/*
//32 bit float time measurment
long measure_32f (int type){

  extern int overflow;
  volatile long s_time;
  volatile long e_time;
  volatile long time;
  volatile long empty_time;
  volatile float a, b, c;
  b = 47.8942;
  c = 3.1415;
  
  // Measure 'empty' case
  s_time = TCNT + (65536)*overflow;
    
  // Empty case
      
  e_time = TCNT + (65536)*overflow;
      
  empty_time = e_time - s_time;
  
  
  // Select arithmatics
  switch(type){ 
    case 0: // Addition
    
      s_time = TCNT + (65536)*overflow;
    
      a = b + c;
      
      e_time = TCNT + (65536)*overflow;
      
      time = e_time - s_time;
      
      break;
      
    case 1: // Multiplication
    
      s_time = TCNT + (65536)*overflow;
    
      a = b * c;
      
      e_time = TCNT + (65536)*overflow;
      
      time = e_time - s_time;
      
      break;
      
    case 2: // Division
    
      s_time = TCNT + (65536)*overflow;
    
      a = b / c;
      
      e_time = TCNT + (65536)*overflow;
      
      time = e_time - s_time;
      
      break;
      
    case 3: // Square root
    
      s_time = TCNT + (65536)*overflow;
    
      a = sqrt(b);
      
      e_time = TCNT + (65536)*overflow;
      
      time = e_time - s_time;
      
      break;
      
    case 4: // Sine
    
      s_time = TCNT + (65536)*overflow;
    
      a = sin(b);
      
      e_time = TCNT + (65536)*overflow;
      
      time = e_time - s_time;
      
      break;
      
    case 5: // Cosine
    
      s_time = TCNT + (65536)*overflow;
    
      a = cos(b);
      
      e_time = TCNT + (65536)*overflow;
      
      time = e_time - s_time;
      
      break;
      
    default: 
      time = 0;
  }
  
  
  return time - empty_time;
}


//64 bit float time measurment
long measure_64f (int type){

  extern int overflow;
  volatile long s_time;
  volatile long e_time;
  volatile long time;
  volatile long empty_time;
  volatile double a, b, c;
  b = 47.89421235;
  c = 3.14151235;
  
  // Measure 'empty' case
  s_time = TCNT + (65536)*overflow;
    
  // Empty case
      
  e_time = TCNT + (65536)*overflow;
      
  empty_time = e_time - s_time;
  
  
  // Select arithmatics
  switch(type){ 
    case 0: // Addition
    
      s_time = TCNT + (65536)*overflow;
    
      a = b + c;
      
      e_time = TCNT + (65536)*overflow;
      
      time = e_time - s_time;
      
      break;
      
    case 1: // Multiplication
    
      s_time = TCNT + (65536)*overflow;
    
      a = b * c;
      
      e_time = TCNT + (65536)*overflow;
      
      time = e_time - s_time;
      
      break;
      
    case 2: // Division
    
      s_time = TCNT + (65536)*overflow;
    
      a = b / c;
      
      e_time = TCNT + (65536)*overflow;
      
      time = e_time - s_time;
      
      break;
      
    case 3: // Square root
    
      s_time = TCNT + (65536)*overflow;
    
      a = sqrt(b);
      
      e_time = TCNT + (65536)*overflow;
      
      time = e_time - s_time;
      
      break;
      
    case 4: // Sine
    
      s_time = TCNT + (65536)*overflow;
    
      a = sin(b);
      
      e_time = TCNT + (65536)*overflow;
      
      time = e_time - s_time;
      
      break;
      
    case 5: // Cosine
    
      s_time = TCNT + (65536)*overflow;
    
      a = cos(b);
      
      e_time = TCNT + (65536)*overflow;
      
      time = e_time - s_time;
      
      break;
      
    default: 
      time = 0;
  }
  
  
  return time - empty_time;
}
//*/

