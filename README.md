# Group_7
# Assignment 2 - C Coding for Microcontrollers

## Group Details
- Henry Kim (SID 470008942)
- William McBean (SID )
- Rishabh Leelchand (SID )
- Wei Ming Chen (SID )

## Group Contributions
Exercise 1: Henry

Exercise 2: 

Exercise 3: 


## High Level Overview

### Exercise 1

Exercise 1 was divided into 3 major modules including timer, measurment and displaying modules.
- Timer: In order to measure the alrithmetic calculations, the timer implemented in HCS12 board was used. The timer with the lowest prescaler of 1 is used with continuous interrupt whenever the timer overflows to check the total time. 
- Measurment: In the measurement module, the timer enabled in timer module is used to achieve the start and end of each arithmetic calculations to derive the durations. The module has comparably repetitive code since the main focus of the module was to measure the pure time without any other unexpected factors varying the duration. Furthermore, each measurement was also subtracted with an 'empty' measurement since there is likely to be delays in actual recording the start and end time as well.
- Displaying: The displaying module arranges the measured values into a table format and sends to the serial to display.

#### Discussion and Remarks


### Exercise 2


#### Discussion and Remarks


### Exercise 3


#### Discussion and Remarks



## Instructions

### Exercise 1

For exercise 1, the process is done all automatically from intiating / disabling the timer and measuring each arithmetic calculations. Each calculation is built to be sent through the serial ports and displayed as the preset layouts. The process will be initiated as the code runs, but as the measurment is done through external clock in the HCS12 board, stepping through the code will affect the outcome values.

### Exercise 2


### Exercise 3



## Testing


### Exercise 1

Various different numbers are used for each data type. For integer and long, negative and positive values with long or short digits were both tested. Furthermore, for 32 bit float, values with over 7 decimal points were also tested and showed that the code simply neglects any digits exceeding the limits, eventually not having any effects on the measured values.

### Exercise 2


### Exercise 3


