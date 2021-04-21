#ifndef MENU_H_
#define MENU_H_

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <pthread.h>
#include "helpers.h"
#include "quit.h"
#include "devices.h"
#include "log.h"
#include "server.h"

//menu size
#define WIDTH 70
#define HEIGHT 20

void* optionsHandler();
void printDeviceToMenu(Data data);
void printSensorToMenu(Sensor sensors);

#endif /* MENU_H_ */