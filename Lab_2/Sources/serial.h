#ifndef SERIAL_HEADER
#define SERIAL_HEADER

// Initiate serial port
void Init_serial(void);

// Send value to serial
void send_serial(char *string);

//Send character to serial
void send_char_serial(char character);

// Convert float to string
void float_to_str(float);

#endif