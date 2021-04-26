#ifndef SERIAL_INTERRUPT_HEADER
#define SERIAL_INTERRUPT_HEADER

#define INPUT_OVERFLOW 1000


// Struct for serial setup
struct serial_parameters {
 
 // Parameters for bits that control serial port configuration 
 int baud_rate_L;
 int baud_rate_H;
 int CR1;
 int CR2; 
 
 // Could do other global variables  
  
};



// Declaration of functions to be used in program
void Init_serial_struct(struct serial_parameters *set_serial);
void send_serial_struct(void);
struct serial_parameters struct_init(void); 

// Define interrupts
__interrupt void serial_1_ISR(void);
__interrupt void serial_0_ISR(void);



#endif