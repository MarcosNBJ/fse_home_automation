#include "i2c.h"

void initI2C(){
    //initializing bme280Init
    
    bme280Init(1, I2C_ADDR);
}

void closeI2C(){
    //closing I2C

    int fd = open("/dev/i2c-1", O_RDWR);
    close(fd);
}

float getTemperature(){
    //using bme280 to get ambient temperature information

    int T, P, H;
    bme280ReadValues(&T, &P, &H);
    return T/100.0;
}

float getHumidity(){
    //using bme280 to get humidity

    int T, P, H;
    bme280ReadValues(&T, &P, &H);
    return H/1000.0;
}