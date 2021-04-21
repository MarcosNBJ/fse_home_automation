#ifndef GPIO_H_
#define GPIO_H_

#include <wiringPi.h>
#include <stdio.h>    
#include <softPwm.h>
#include <unistd.h>
#include "server.h"

//defining the pins for each device/sensor
#define LAMP1 0
#define LAMP2 1
#define LAMP3 2
#define LAMP4 3
#define AR1 23
#define AR2 24
#define PRES1 6
#define PRES2 25
#define ABR1 21
#define ABR2 22
#define ABR3 26
#define ABR4 27
#define ABR5 28
#define ABR6 29

void initGPIO(); //initialize gpio with wiringpi
void toggleDevice(int item, int status); //toggle device on and off
void setAllOff(); // shut off every device
void* handleGPIO(); //handle sensor state changes

#endif /* GPIO_H_ */