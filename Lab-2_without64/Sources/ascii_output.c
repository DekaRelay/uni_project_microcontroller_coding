//#include <string.h>
#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include "serial.h" 
#include "ascii_output.h"
#define BUFFER_SIZE 100

int i;
int j;
int k;
char ascii_array[7][85];
int char_count;
int line_count;
extern char buffer[BUFFER_SIZE];
extern int buffer_index;


//Function to convert time float array into string table array    
char** ascii_table(float **time){
    
    //add the border lines
    line_count = 0;
    for(i = 0 ; i<7 ; i=i+2){
      line_count = 0;
      for(j = 0 ; j<7 ; j++){
        
        ascii_array[i][line_count] = '+';
        line_count++;
        for(k = 0 ; k < 10 ; k++){
            
            ascii_array[i][line_count] = '-';
            line_count++;
        }
      }
      ascii_array[i][line_count] = '+';
      line_count++;
      ascii_array[i][line_count] = '\0';
      //ascii_array[i] = "+----------+----------+----------+----------+----------+----------+----------+";
      
    }
    
    k = 1;
    for(i = 0 ; i <3 ; i++){        //loop through float time array
      
      ascii_array[k][0] = '|';    //add the first borderline
      line_count = 1;
      
      for(j = 0 ; j<6 ; j++){       //loop through individual floats

        float_to_str(time[i][j]);       //convert num to string
        char_count = 0;
        
        while(char_count <= buffer_index){     //add string to the ascii
          ascii_array[k][line_count] = buffer[char_count];
          line_count++;
          char_count++; 
        }
        
        while(char_count <= 10){
          ascii_array[k][line_count] = ' ';   //add the spaces to line
          line_count++;
          char_count++;
           
        }
        ascii_array[k][line_count] = '|'; //add | to line
        line_count++;
      }
      ascii_array[k][line_count] = '\0';  //add null char to end of string
      k = k +2;
    }
    
    return ascii_array;
  
}