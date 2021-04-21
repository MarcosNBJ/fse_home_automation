#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <dataRetrieval.h>
#include "quit.h"
#include "menu.h"
#include "devices.h"
#include "server.h"
#include "log.h"

int main() {

	//Attaching Ctrl+C to quit handler
	signal(SIGINT, quit);

	//creating logFILE
	createCSV();

	//initializing informations to be printed
	dataInit();

	//one thread for the menu, another for communication with the distributed servers
	//and another to handle data updating
	pthread_t dataRetrieval, menu, server;

	pthread_create(&dataRetrieval, NULL, updateData, NULL);
	pthread_create(&menu, NULL, optionsHandler, NULL);
	pthread_create(&server, NULL, receiveCommands, NULL);

	pthread_join(dataRetrieval, NULL);
	pthread_join(menu, NULL);
	pthread_join(server, NULL);

	return 0;
}
