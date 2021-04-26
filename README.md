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

* **Selecting the Exercise to Run** <br>
1. Connect the Dragon board to both the Codewarrior debugger and the PC running putty

2. Set up the putty.
   * Open putty then open the serial connection setting.
   * Change flow control to none.
   * Set the baud rate to 9600 and data to 8 bit.
   * Go to session tab and go to serial.
   * Connect to the COM specified in your device manager and click open.

3. Open the folder "Lab_2_Demo" and run Lab_2fin.mcp.

4. Select the relevant program you want to run by modifying the ex_num variable. The value you input will determine which exercise is run, with the value corresponding to the exercise number
   * setting ex_num = 1 will run exercise 1.

* **Running exercise 1** <br>
1.  Click debug to start the program.

2.  Click run to run the code thoroughly instead of stepping. Note: Stepping will result in accuracy loss.

3.  The data will be displayed onto the putty terminal in tabular format.

* **Running exercise 2** <br>
1.  Change the program into simulation

2.  Click debug to start the program. Click run to run the code.

3.  Type into the simulated terminal in both SCI0 and SCI1.

4.  The characters typed into the terminal will appear on the terminal in real time.

* **Running exercise 3** <br>
1.  Click debug to start the program. Click run to run through the code.

2.  Move the accelerometer

3.  The values for acceleration and downwards direction will appear on the putty terminal in real time

## Details about testing procedures

* **Module 1: Benchmarking the performance of arithmetic functions** <br>

   input range:
   constraints/limitations: - maybe talk about inputs to the table
   outputs:
   testing procedure:


Tested out various different type of values for all integer, long, 32 bit float and 64 bit float.

Integer: Different length of numbers used (ie. b = 10, c = 5 / b = 255, c = 125 / b = 500, c = 17)
Long: Relatively longer digits were used (ie. b = 1000000, c = 800000 / b = 1234567, c = 876543)
32-bit float: Both short and long digits with decimal places were tested. Discovered that decimal places over 7 digits simply gets removed, having no impact on the measured time.
64-bit float: Relatively longer digits with decimal places were tested.
Note: Every first measurement time showed unexpected larger value, therefore the initial measurement is duplicated and the second value is used!

* **Module 2: Serial with interrupts** <br>


* **Module 3: Reading data from accelerometer** <br>


