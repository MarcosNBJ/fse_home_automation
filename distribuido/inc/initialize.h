#ifndef INITIALIZE_H_
#define INITIALIZE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"


void init_device_info_from_json(const char * const devices_json);
int getNumberOfDevices();
char *getIP();
int *getOutputDevices();
int getPort();
#endif /* INITIALIZE_H_ */
