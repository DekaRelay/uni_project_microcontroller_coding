#include "timers.h"

// include the register/pin definitions
#include "derivative.h"

extern int overflow;

// function to initialise timer
void Init_Timer (void) {
 // Optimise timer
 TSCR1 = 0x80;         // Enable timer
 TSCR2 = 0x80;         // Set prescaler to one , timer overflow interrupt enable
 TFLG2 = 0x80;          // Reset interrupt flag TOF     

}

// function to stop timer
void Stop_Timer (void) {
  TSCR1 = 0x00;        // Disable timer
}

// define overflow interrupt for timer
#pragma CODE_SEG __NEAR_SEG NON_BANKED
__interrupt void TOF_ISR(void){

  overflow++;
  TFLG2 = 0x80;        // Reset interrupt flag TOF     

}