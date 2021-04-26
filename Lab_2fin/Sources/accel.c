#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include "accel.h"

extern unsigned input[3];
extern float acceleration[3];
extern int TDRE_BIT;

extern int str_index, x_index, y_index, z_index;
extern char str[6], x_accel[6], y_accel[6], z_accel[6];



///** ACD functions **///

void read_data(void) {

  ATD1CTL5 = 0x98;

  while (!(ATD1STAT0 & 0x80));

  input[0] = ATD1DR0;

  input[1] = ATD1DR1;

  input[2] = ATD1DR2;  
  
}

  
void init_ADC(void) {
  
  ATD1CTL2 = 0x80;        // Turn on ADC, with interrupt enabled	
  ATD1CTL3 = 0x98;        // three conversion, no FIFO
  ATD1CTL4 = 0xEB;        // 8-bit resolution, 16-clock for 2nd phase,
                          // prescaler of 24 for Conversion Freq=1MHz                   
  
}


void calc_acc(void) {

  int i;
  for (i = 0; i < 3; i++) {
    acceleration[i] = (((((float)input[i]*5.12/255)-1.65)/0.44)*9.81);   // transform each value into acceleration       
  }

}



///** serial functions **///

// Function to send a string to serial
void send_serial_accel(char *str, int index){
  
  int i;
  for (i = 0; i < index; i++) {
    
   while(!(SCI1SR1 & TDRE_BIT));  // Wait for the TDRE to be clear
   
   SCI1DRL = str[i];                // write the character to serial   
   
  }
  
  // send a space after the message
  while(!(SCI1SR1 & TDRE_BIT));  // Wait for the TDRE to be clear   
  SCI1DRL = ' ';                 // write space to serial   
  
  
}



// Function to transform a float into a string
void float2str(float n) {
  
  int absolute = 1;
  int dVal, dec;
  str_index = 0;
  
  if (n < 0) {
    absolute = -1;    
  }
  
  dVal = (int)n * absolute;
  dec = (int)(n * 100 * absolute) % 100;
  
  str[str_index++] = (dec % 10) + '0';
  str[str_index++] = (dec / 10) + '0';  
  str[str_index++] = '.';
  
  while (dVal > 0) {
     
    str[str_index++] = (dVal % 10) + '0';
    dVal /= 10;
      
  }
  
  if (n < 0) {
   
   str[str_index++] = '-';
    
  }
  
  
}

  



// Figuring out which way is down  
void direction2serial(float x_acc, float y_acc, float z_acc) {
  
  char direction[] = {'D', 'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', ':'};
  char msg_positive[] = {'P','o','s','i','t','i','v','e',' ','d','i','r','e','c','t','i','o','n'};
  char msg_negative[] = {'N','e','g','a','t','i','v','e',' ','d','i','r','e','c','t','i','o','n'};
  float x_s, y_s, z_s, x_acc_abs, y_acc_abs, z_acc_abs;     // initialise variables to record the distance from 9.8
  float x_s_abs, y_s_abs, z_s_abs;
  float smallest_num;
  char smallest;
  
  
  
  // write direction message to serial
  send_serial_accel(&direction, 10);
  
  x_acc_abs = f_abs(x_acc);
  y_acc_abs = f_abs(y_acc);
  z_acc_abs = f_abs(z_acc);
    
  x_s = 9.8 - x_acc_abs;
  y_s = 9.8 - y_acc_abs;
  z_s = 9.8 - z_acc_abs;
  
  x_s_abs = f_abs(x_s);
  y_s_abs = f_abs(y_s);
  z_s_abs = f_abs(z_s);
   
   
   
  // start by assuming the smallest is x_s
  smallest_num = x_s_abs;
  smallest = 'X';
     
  if (y_s_abs < smallest_num) {
    smallest_num = y_s_abs;
    smallest = 'Y';
  }
  
  if (z_s_abs < smallest_num) {
    smallest = 'Z'; 
  }
   
  while(!(SCI1SR1 & TDRE_BIT));      // Wait for the TDRE to be clear   
  SCI1DRL = smallest;                // write CR to serial
  
  
  
  // Determine appropriate message to print after the axis
    
  if (smallest == 'X') {
    if (x_acc < 0) {    
      send_serial_accel(&msg_positive, 18);   
    } 
    else {
      send_serial_accel(&msg_negative, 18);
    }    
  }
  
  if (smallest == 'Y') {
    if (y_acc < 0) {    
      send_serial_accel(&msg_positive, 18);   
    } 
    else {
      send_serial_accel(&msg_negative, 18);
    }    
  }
  
  if (smallest == 'Z') {
    if (z_acc < 0) {    
      send_serial_accel(&msg_positive, 18);   
    } 
    else {
      send_serial_accel(&msg_negative, 18);
    }    
  }
     
}


// Function to do absolute value of a float

float f_abs(float a) {
  
  if (a < 0) {  
    a = a * -1;    
  }
  return a;
  
}
