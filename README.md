# Group_7
# Lab 2 - C Coding for Microcontrollers

The aim of this lab is to demonstrate how the microcontroller handles memory using pointers and iterators, demonstrate the use of interrupts, demonstrate the use of timers and to perform an integration of software modules.

## Group Members

- Henry Kim (SID 470008942)
- William McBean (SID 490404595)
- Rishabh Leelchand (SID )
- Wei Ming Chen (SID )

## Detail about the project

There are 4 Group members in this project, two in person and two online members. To ensure the ease of completion this project was broken into modules and modules were distributed to each group member. The role of each group member is shown below:

- Rishabh Leelchand:
- Henry Kim:
- Wei Ming:
- William McBean: The primary role of William in this lab was to see the completion of Exercise 2 and 3. To do this he worked collaboratively with Wei Ming. He also contributed to the collaboration of the exercise modules and the documentation. 

Each group member is responsible for the collaboration and completion of the project. This means that each group member is held accountable to communicate with other members efficiently and complete their assigned tasks on time.

## High Level Overview

The code in this project is divided into 3 main modules:
* **Module 1: Benchmarking the performance of arithmetic functions** <br>
Module 1 calculates the time taken for different math operations within the microcontroller and outputs this data to the serial port in tabular form
* **Module 2: Serial with interrupts** <br>
Module 2 recieves input from both serial port 0 and 1 via interrupts and outputs this data back towards the same serial port.
* **Module 3: Reading data from accelerometer** <br>
Module 3 reads analog input from an external accelerometer and transforms it into a live feed of the acceleration values. Moreover, this module takes these values and trasmits a live feed to the serial port displaying the current acceleration along the axes and the axis pointing in the downward direction.

Each of these three main modules were broken into sets of functions to perform the task specifically.

*  **Exercise 1** <br>
Exercise 1 was divided into 3 major modules including timer, measurment and displaying modules.

    * Timer <br>
In order to measure the alrithmetic calculations, the timer implemented in HCS12 board was used. The timer with the lowest prescaler of 1 is used with continuous interrupt whenever the timer overflows to check the total time. 

    * Measurement <br>
In the measurement module, the timer enabled in timer module is used to achieve the start and end of each arithmetic calculations to derive the durations. The module has comparably repetitive code since the main focus of the module was to measure the pure time without any other unexpected factors varying the duration. Furthermore, each measurement was also subtracted with an 'empty' measurement since there is likely to be delays in actual recording the start and end time as well.

    * Displaying <br>
The displaying module arranges the measured values into a table format and sends to the serial to display.

*  **Exercise 2** <br>
Exercise 2 was broken into 4 major modules including the serial initialisation, SCIO interrupt, SCI1 interrupt and send serial modules.
    
    * Serial initialisation <br>
The serial port was initialised using a struct software module which contained the relevant values for each register. A function goes through all the registers and sets them to the appropriate value.

    * SCIO and SCI1 interrupt <br>
The serial recieve was executed using the SCI0 and SCI1 interrupts. When the interrupts occured the incomming character was stored into a buffer to be later outputted.

    * Send serial <br>
Using the data stored in the buffer, this module outputs the recieved character through to the same port it was recieved from.


*  **Exercise 3** <br>
Exercise 3 was broken into 5 major modules including the serial and ATD initialisation, ATD read, Acceleration conversion and direction calculation.

    * Serial and ATD initialisation <br>
The serial port was initialised using the appropriate parameters to achieve a normal output. The ATD was initialised to perform three conversions with an 8-bit resolution.

    * ATD read <br>
Reading from the accelerometer was achieved by reading from the ATD1 registers. This provided a digital input of the accelerometer data which could later be converted into a readable value.

    * Acceleration conversion <br>
The digital values retrieved from the accelerometer were converted into actual acceleration values using a formula retrieved from the KXPS5-3157 data sheet. These values are then outputed in real time to the serial port

    * Direction calculation <br>
The downward direction of the accelerometer was then calculated as the closest axis facing downward and outputted to the serial port in real time.




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


