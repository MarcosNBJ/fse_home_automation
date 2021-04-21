#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "server.h"
#include "gpio.h"
#include "quit.h"
#include "i2c.h"

int main() {

	//registering Ctrl+C to quit function
	signal(SIGINT,quit);

	//initializing GPIO and I2C
	initGPIO();
	initI2C();

	//setting off all devices, in case there were any on before the launch
	setAllOff();

	//one thread for the server, which will communicate with the central
	//and another for the gpio, which will monitor and interact with all gpio devices/sensors
	pthread_t server, gpio;

	pthread_create(&server, NULL, receiveFromCentral, NULL);
	pthread_create(&gpio, NULL, handleGPIO, NULL);

	pthread_join(server, NULL);
	pthread_join(gpio, NULL);
	
	return 0;
}
