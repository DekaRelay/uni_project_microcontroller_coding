//#include <string.h>
#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include "serial.h" 
#include "ascii_output.h"
#define BUFFER_SIZE 100

int i;
int j;
int k;
extern char ascii_array[11][85];
char top_label[] = "|          |Add       |Multiply  |Division  |SquareRoot|Sine      |Cosine    |";
int char_count;
int line_count;
extern char buffer[BUFFER_SIZE];
extern int buffer_index;


//Function to convert time float array into string table array    
void ascii_table(float time[4][6]){
    
    
    //add the border lines
    line_count = 0;
    for(i = 0 ; i<11 ; i=i+2){
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
      
    }
    
    for(i = 0 ; i<78 ; i++){
      ascii_array[1][i] = top_label[i];    
    }
    
    k = 3;
    for(i = 0 ; i <4 ; i++){        //loop through float time array
      
      ascii_array[k][0] = '|';    //add the first borderline
      line_count = 1;
      if(i == 0){
        ascii_array[k][1] = 'i';
        ascii_array[k][2] = 'n';
        ascii_array[k][3] = 't';
        for(j = 4 ; j<11 ; j++){
          ascii_array[k][j] = ' ';
        }
      }else if(i == 1){
        ascii_array[k][1] = 'l';
        ascii_array[k][2] = 'o';
        ascii_array[k][3] = 'n';
        ascii_array[k][4] = 'g';
        for(j = 5 ; j<11 ; j++){
          ascii_array[k][j] = ' ';
        }
      }else if(i == 2){
        ascii_array[k][1] = '3';
        ascii_array[k][2] = '2';
        ascii_array[k][3] = 'b';
        ascii_array[k][4] = 'i';
        ascii_array[k][5] = 't';
        for(j = 6 ; j<11 ; j++){
          ascii_array[k][j] = ' ';
        }  
      }else if(i == 3){
        ascii_array[k][1] = '6';
        ascii_array[k][2] = '4';
        ascii_array[k][3] = 'b';
        ascii_array[k][4] = 'i';
        ascii_array[k][5] = 't';
        for(j = 6 ; j<11 ; j++){
          ascii_array[k][j] = ' ';
        }  
      }
      ascii_array[k][11] = '|';
      line_count = 12;
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
      //ascii_array[k][line_count] = 13;
      //line_count++;
      ascii_array[k][line_count] = '\0';  //add null char to end of string
      k = k +2;
    }
    
    //return ascii_array;
  
}