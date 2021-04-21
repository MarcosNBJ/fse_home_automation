#ifndef I2C_H_
#define I2C_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "bme280.h"

//I2C address
#define I2C_ADDR 0x76

void initI2C(); //initializing I2C for BME280
float getTemperature(); //using BME to get temperature
float getHumidity(); //using BME to get humidity
void closeI2C(); //closing I2C

#endif
