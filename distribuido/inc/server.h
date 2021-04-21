#ifndef SERVER_H_
#define SERVER_H_

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include "gpio.h"
#include "i2c.h"

// central server information
#define SERVER_CENTRAL_IP "192.168.0.53"
#define SERVER_CENTRAL_PORT 10020
#define SERVER_DISTRIBUTED_PORT 10120

void* receiveFromCentral(); //receive messages from central server
void sentToCentral(char *message); //send messages to central server

#endif /* SERVER_H_ */
