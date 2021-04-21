#ifndef ALARM_H_
#define ALARM_H_

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "devices.h"

void createAlarm(); //creates alarm thread, to play and stop playing 
void setAlarmOff(); //stops the alarm

#endif /* ALARM_H_ */