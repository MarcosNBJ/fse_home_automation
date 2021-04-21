#ifndef DEVICES_H_
#define DEVICES_H_

#include "helpers.h"
#include "server.h"
#include "menu.h"
#include "dataRetrieval.h"
#include "alarm.h"

#define LAMP1 0
#define LAMP2 1
#define LAMP3 2
#define LAMP4 3
#define AR1 23
#define AR2 24

void initDevicesAndSensors(); //initializing devices and sensors information
void updateDevices(Device devices); //updates device states 
void sensorsHandler(int command); //handle sensor state chages
Device getDevices(); //get current device states

#endif /* DEVICES_H_ */