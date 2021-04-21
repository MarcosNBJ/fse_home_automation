#ifndef DATARETRIEVAL_H_
#define DATARETRIEVAL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "helpers.h"
#include "menu.h"
#include "devices.h"
#include "server.h"

void dataInit(); //initializing temperature/humidity data as zeros
void* updateData(); //at each second, requests new BME info to update screen
Data getCurrentData(); //returns current data

#endif /* DATARETRIEVAL_H_ */