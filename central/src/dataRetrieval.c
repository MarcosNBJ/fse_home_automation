#include "dataRetrieval.h"

//used to keep data regarding the BME280 info and devices info
Data received_data;

void dataInit() {
  //initializing data with zeros
  received_data.bme280.temperature = 0;
  received_data.bme280.humidity = 0;
}

Data getCurrentData() {
  //returns the current data
  return received_data;
}

void* updateData() {
  /*
    At each second, updates new BME received info
    to menu
  */

  while (1) {
    // request new BME info
    BME280 bme280 = readBMEInfo();

    received_data.bme280 = bme280;

    Device devices;
    devices = getDevices();
    received_data.devices = devices;

    //print to menu
    printDeviceToMenu(received_data);

    // 1 second
    usleep(1000000);
  }

  return NULL;
}
