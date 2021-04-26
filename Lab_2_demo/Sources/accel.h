#ifndef ACCEL_HEADER
#define ACCEL_HEADER

///** ADC functions **///

void init_ADC(void);
void read_data(void);
void calc_acc(void);


///** serial functions **///

void send_serial_accel(char *str, int index);
void float2str(float n);
void direction2serial(float x_acc, float y_acc, float z_acc);
float f_abs(float a);


#endif