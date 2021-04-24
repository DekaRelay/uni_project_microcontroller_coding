#ifndef TIMERS_HEADER
#define TIMERS_HEADER

// function to initialise the timer
void Init_Timer (void);

// Timer interrupt definition
__interrupt void TOF_ISR(void);



#endif