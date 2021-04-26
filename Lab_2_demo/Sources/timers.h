#ifndef TIMERS_HEADER
#define TIMERS_HEADER

// function to initialise the timer
void Init_Timer (void);

// function to stop timer
void Stop_Timer (void);

// Timer interrupt definition
__interrupt void TOF_ISR(void);


#endif