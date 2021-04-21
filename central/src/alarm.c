#include "alarm.h"

//variable to control if the alarm should be playing or not
int playing = 0;

void* play() {
  //plays the alarm as long as the control variable implies so

  while (playing == 1) {

    //going to the previous directory, which contains the audio file, and playing with omxplayer
    //the output of the command is being redirected to not mess with the program screen 
    system("cd ..; omxplayer alarm.mp3 > /dev/null");
  }

  return NULL;
}

void createAlarm() {
  //gets current state of all devices, as the alarm is stored along them
  Device devices = getDevices();

  //if the alarm flag is set to true, then we create a thread to play it
  if (devices.alarm) {
    devices.playing = 1;
    playing = 1;
    pthread_t alarm;
    pthread_create(&alarm, NULL, play, NULL);

    //also updating devices, for the menu to perceive alarm change
    updateDevices(devices);
  }
}

void setAlarmOff() {

  // sets the control variable to false, turning off the alarm
  playing = 0;
}
