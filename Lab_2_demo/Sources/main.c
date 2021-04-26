#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include "timers.h"
#include "measure.h"
#include "serial.h"
#include "ascii_output.h"
#include "serial_int.h"
#include "accel.h"
#define BUFFER_SIZE 100   /* allocated memory for serial input  */

//------------ Global Variables--------------------------
int TDRE_BIT = 0x80;

// Exercise 1 Global Variables
int overflow = 0;
char buffer[BUFFER_SIZE];
int buffer_index;
char ascii_array[11][85];

// Exercise 3 Global Variables
unsigned input[3];
float acceleration[3];
int str_index, x_index = 0, y_index = 0, z_index = 0;
char str[6], x_accel[6], y_accel[6], z_accel[6];




//---------------- Main function from here -------------------------
void main(void) {
  /* put your own code here */

    //------ Select Demonstration ---------
    /*************************************/
    /*********/int ex_num = 1;/***********/
    /*************************************/
    //-------------------------------------
    
    // Time measurement arrays
    float time[4][6];

    int i;                                                // Counter for loops
    float prescaler = 41.6*0.001;                         // microseconds
    
    struct serial_parameters set_serial = struct_init();  // Serial parameter in structure format
   
 
 	EnableInterrupts;
 	
 	
  //------------------------ Exercise 1 ----------------------------
  if(ex_num == 1){
    
   
    // Initiate timer
    Init_Timer();


    // Measure time for arithmatics and save to 2D array
    for (i = 0; i < 6; i++){
      time[0][i] = measure_int(i) * prescaler;
      time[1][i] = measure_long(i) * prescaler;
      time[2][i] = measure_32f(i) * prescaler;
      time[3][i] = measure_double(i) * prescaler;   
    }

    // Stop timer
    Stop_Timer();


    // Enter function to initialise serial
    Init_serial();
    
    // Convert to table format & Send to serial
    ascii_table(time);                                    // Convert float into table layout
    for(i = 0 ; i<11 ; i++){
      
      send_serial(ascii_array[i]);
      send_char_serial(13);	
    
    }
    
    
    
  //------------------------ Exercise 2 -----------------------------
  }else if(ex_num == 2){
  
    Init_serial_struct(&set_serial);                      // Enter function to initialise serial interupt   


  //------------------------ Exercise 3 -----------------------------
  }else if(ex_num == 3){
    init_ADC();             

    Init_serial();                                        // initialise serial

  }


  for(;;) {
  
  if(ex_num == 2) send_serial_struct();                   // Send characters from serial
  else if(ex_num == 3){
    
    read_data();                                          // read data from the accelerometer using polling
       
    calc_acc();                                           // calculate the acceleration from the data
    
    
    
            
    ///** Output live feed of acceleration to serial **///
    /* Add additional characters indicating x, y, z*/

    float2str(acceleration[0]);                           // Convert float to string
    
    x_accel[x_index++] = 'x';                             // Add additional character 'x:
    x_accel[x_index++] = ':';                             // Same for y and z below
    
    for (i = str_index-1; i >= 0; i--) {   
      x_accel[x_index++] = str[i];      
    }
    
    
    
    float2str(acceleration[1]);   
    
    y_accel[y_index++] = 'y';
    y_accel[y_index++] = ':';
    
    for (i = str_index-1; i >= 0; i--) {   
      y_accel[y_index++] = str[i];      
    }



    float2str(acceleration[2]);
    
    z_accel[z_index++] = 'z';
    z_accel[z_index++] = ':';
    
    for (i = str_index-1; i >= 0; i--) {   
      z_accel[z_index++] = str[i];      
    }


    // Send x, y, z string to serial
    send_serial_accel(x_accel, x_index);
    send_serial_accel(y_accel, y_index);
    send_serial_accel(z_accel, z_index);                   
    
    x_index = 0;                                           // reset indexes to be able to read again
    y_index = 0;
    z_index = 0;


    // output the axis direction to the serial
    direction2serial(acceleration[0], acceleration[1], acceleration[2]);    


    // send a carriage return to reset the line
    
    while(!(SCI1SR1 & TDRE_BIT));                         // Wait for the TDRE to be clear   
    SCI1DRL = 0x0D;                                       // write CR to serial
                                                                  
    
    _FEED_COP();                                          // feeds the dog   
    
  }
    
    
    
    
    
  } /* loop forever */
  /* please make sure that you never leave main */
}