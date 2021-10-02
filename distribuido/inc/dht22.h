
#ifndef __DHT22__
#define __DHT22__

#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_TIMINGS	85
#define DEBUG 0
#define WAIT_TIME 2000

uint8_t dht_pin = 28;  //  GPIO 20 (wiringPi 28)


int initDht22();
void printUsage();
int read_dht_data();
float getTemperature();
float getHumidity();

#endif // __DHT22__