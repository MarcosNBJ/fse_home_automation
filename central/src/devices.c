#include "devices.h"

Device _devices; //lamps and ar conditioners
Sensor _sensors; //all sensors

void initDevicesAndSensors() {

  //initializing everything to 0, to not mess the menu
  _devices.lamp1 = 0;
  _devices.lamp2 = 0;
  _devices.lamp3 = 0;
  _devices.lamp4 = 0;
  _devices.ar1 = 0;
  _devices.ar2 = 0;
  _devices.alarm = 0;
  _devices.playing = 0;

  _sensors.pres1 = 0;
  _sensors.pres2 = 0;
  _sensors.abr1 = 0;
  _sensors.abr2 = 0;
  _sensors.abr3 = 0;
  _sensors.abr4 = 0;
  _sensors.abr5 = 0;
  _sensors.abr6 = 0;

  //getting current info regarding BME and sensors
  Data data = getCurrentData();

  //the devices are set only through central control
  //so we keep the zeros
  data.devices = _devices;

  //print initial state to ncurses menu
  printDeviceToMenu(data);
  printSensorToMenu(_sensors);
}

int anyActiveSensor(){
  //returns true if there's any active sensor

  return (_sensors.pres1 || _sensors.pres2 || _sensors.abr1 || _sensors.abr2
         || _sensors.abr3 || _sensors.abr4 || _sensors.abr5 || _sensors.abr6);
}

void sensorsHandler(int command) {
  //handles changes on sensor states
  //if a change was detected, invert the sensor

  if (command == 1) {
    _sensors.pres1 = !_sensors.pres1;
  }
  if (command == 2) {
    _sensors.pres2 = !_sensors.pres2;
  }
  if (command == 3) {
    _sensors.abr1 = !_sensors.abr1;
  }
  if (command == 4) {
    _sensors.abr2 = !_sensors.abr2;
  }
  if (command == 5) {
    _sensors.abr3 = !_sensors.abr3;
  }
  if (command == 6) {
    _sensors.abr4 = !_sensors.abr4;
  }
  if (command == 7) {
    _sensors.abr5 = !_sensors.abr5;
  }
  if (command == 8) {
    _sensors.abr6 = !_sensors.abr6;
  } 

  //if there's any active sensor, plays the alarm
  if (anyActiveSensor()) {
    createAlarm();
  } else {

    //otherwise, the alarm should be off
    Data data = getCurrentData();
    _devices.playing = 0;
    setAlarmOff();
    data.devices = _devices;

    //updates devices in ncurses menu, as the alarm is one of them
    printDeviceToMenu(data);
  }

  //printing sensors to ncurses menu
  printSensorToMenu(_sensors);
}

void updateDevices(Device devices) {

  //if the user chooses to deactivate the alarm
  if (!devices.alarm) {
    devices.playing = 0;
    setAlarmOff();
  }

  //if the user has chosen to activate the alarm and there's any sensor active
  if (devices.alarm  && anyActiveSensor()) {
    devices.playing = 1;
  }
  
  //getting current device information
  //along with new user input
  Data data = getCurrentData();
  data.devices = devices;
  printDeviceToMenu(data);

  //if the user has chosen to change any device
  //then we send that requisition to the distributed server
  //responsible for making the change
  int res = 1;
  if (devices.lamp1 != _devices.lamp1) {
    res = sendCommands(LAMP1, devices.lamp1);
  }
  if (devices.lamp2 != _devices.lamp2) {
    res = sendCommands(LAMP2, devices.lamp2);
  }
  if (devices.lamp3 != _devices.lamp3) {
    res = sendCommands(LAMP3, devices.lamp3);
  }
  if (devices.lamp4 != _devices.lamp4) {
    res = sendCommands(LAMP4, devices.lamp4);
  }
  if (devices.ar1 != _devices.ar1) {
    res = sendCommands(AR1, devices.ar1);
  }
  if (devices.ar2 != _devices.ar2) {
    res = sendCommands(AR2, devices.ar2);
  }

  if (res) {
    _devices = devices;
  }
}

Device getDevices() {
  //get current device states
  return _devices;
}
