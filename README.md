# Group_7
# Lab 2 - C Coding for Microcontrollers

The aim of this lab is to demonstrate how the microcontroller handles memory using pointers and iterators, demonstrate the use of interrupts, demonstrate the use of timers and to perform an integration of software modules.

## Group Members

- Henry Kim (SID 470008942)
- William McBean (SID 490404595)
- Rishabh Leelchand (SID 490296808)
- Wei Ming Chen (SID 470351332)

## Detail about the project

There are 4 Group members in this project, two in person and two online members. To ensure the ease of completion this project was broken into modules and modules were distributed to each group member. The role of each group member is shown below:

- Rishabh Leelchand: Primary focus being the ascii table format of exercise 1 and making sure the output could be printed to the serial port
- Henry Kim: Mainly focused on Exercise 1 especially handling the timer to measure arithmetic calculations and converting them into string type data.
- Wei Ming:
- William McBean: The primary role of William in this lab was to see the completion of Exercise 2 and 3. To do this he worked collaboratively with Wei Ming. He also contributed to the collaboration of the exercise modules and the documentation.

Each group member is responsible for the collaboration and completion of the project. This means that each group member is held accountable to communicate with other members efficiently and complete their assigned tasks on time.

## High Level Overview

The code in this project is divided into 3 main modules:
- Module 1: Benchmarking the performance of arithmetic functions
Module 1 calculates the time taken for different math operations within the microcontroller and outputs this data to the serial port in tabular form
- Module 2: Serial with interrupts
Module 2 recieves input from both serial port 0 and 1 via interrupts and outputs this data back towards the same serial port.
- Module 3: Reading data from accelerometer
Module 3 reads analog input from an external accelerometer and transforms it into a live feed of the acceleration values. Moreover, this module takes these values and trasmits a live feed to the serial port displaying the current acceleration along the axes and the axis pointing in the downward direction.

Each of these three main modules were broken into sets of functions to perform the task specifically.

### Exercise 1

Exercise 1 was divided into 3 major modules including timer, measurment and displaying modules.
- Timer: In order to measure the alrithmetic calculations, the timer implemented in HCS12 board was used. The timer with the lowest prescaler of 1 is used with continuous interrupt whenever the timer overflows to check the total time.
- Measurment: In the measurement module, the timer enabled in timer module is used to achieve the start and end of each arithmetic calculations to derive the durations. The module has comparably repetitive code since the main focus of the module was to measure the pure time without any other unexpected factors varying the duration. Furthermore, each measurement was also subtracted with an 'empty' measurement since there is likely to be delays in actual recording the start and end time as well.
- Displaying: The displaying module arranges the measured values into a table format and sends to the serial to display. Measured float data were converted to string upto 2 decimal places with unit of microseconds.

#### Discussion and Remarks


### Exercise 2


#### Discussion and Remarks


### Exercise 3


#### Discussion and Remarks



## Instructions

### Exercise 1

In order to get the measured data, serial connection is required on SCI1 with 'Putty'.
- Connect both SCI0 and SCI1 of the board to the PC before running the code.
- Set Putty baud rate to 9600 and data to 8 bit. Select correct COM port that is connected to SCI1 of the board.
- Run the code thoroughly, instead of stepping. **Note: Stepping will result in accuracy loss**
- Data will be displayed onto the Putty terminal in a table format.

### Exercise 2


### Exercise 3



## Testing


### Exercise 1

Tested out various different type of values for all integer, long, 32 bit float and 64 bit float.
- Integer: Different length of numbers used (ie. b = 10, c = 5 / b = 255, c = 125 /  b = 500, c = 17)
- Long: Relatively longer digits were used (ie. b = 1000000, c = 800000 / b = 1234567, c = 876543)
- 32-bit float: Both short and long digits with decimal places were tested. Discovered that decimal places over 7 digits simply gets removed, having no impact on the measured time.
- 64-bit float: Relatively longer digits with decimal places were tested.

**Note: Every first measurement time showed unexpected larger value, therefore the initial measurement is duplicated and the second value is used!**


### Exercise 2


### Exercise 3
