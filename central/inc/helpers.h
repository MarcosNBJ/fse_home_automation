#ifndef HELPERS_H_
#define HELPERS_H_

/* Helper header to define gobaly used data structures*/

typedef struct Device{
  int lamp1;
  int lamp2;
  int lamp3;
  int lamp4;
  int ar1;
  int ar2;
  int alarm;
  int playing;
} Device; //devices and alarm

typedef struct Sensor{
  int pres1;
  int pres2;
  int abr1;
  int abr2;
  int abr3;
  int abr4;
  int abr5;
  int abr6;
} Sensor; //sensors

typedef struct {
  double temperature;
  double humidity;
} BME280; //bme info

typedef struct {
  BME280 bme280;
  Device devices;
} Data; //bme info and devices, because they are on the same side of the menu


#endif /* HELPERS_H_ */