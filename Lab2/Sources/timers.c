#include "timers.h"

#include "derivative.h"

extern int count;

void Init_TC7 (void) {
  
  TSCR1 = 0x90;  // enable timer, enable fast flag reset
  TSCR2 = 0x00;  // set the perscalar to one
  TIE = 0x80;    // enable interrupt
}


// Interrupt
#pragma CODE_SEG __NEAR_SEG NON_BANKED
__interrupt void TC7_ISR(void) {
  
  TC7 = TCNT + (word)62500;  // 12 Hhz and PT7
  count++;
}
  