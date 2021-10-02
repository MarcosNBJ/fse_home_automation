#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "server.h"
#include "gpio.h"
#include "quit.h"
#include "dht22.h"

int main() {

	//registering Ctrl+C to quit function
	signal(SIGINT,quit);

	//initializing GPIO and dht22
	initGPIO();
	initDht22();

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
