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
#include "helpers.h"
#include "quit.h"
#include "alarm.h"
#include "devices.h"

//ip and port communication info
#define SERVER_DISTRIBUTED_IP "192.168.0.4"
#define SERVER_CENTRAL_PORT 10020
#define SERVER_DISTRIBUTED_PORT 10120

void* receiveCommands(); //to receive commands from distributed
int sendCommands(int item, int status); //to send commands to distributed
BME280 readBMEInfo(); //to read new BME info

#endif /* SERVER_H_ */
