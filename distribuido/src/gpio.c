#include "gpio.h"

void initGPIO() {
  //inits gpio with wiring pi

  wiringPiSetup();
}

void toggleDevice(int item, int status) {
  //used to set a device, such as a lamp, on or off

  pinMode(item, OUTPUT);
  digitalWrite(item, status);
}

/*
  Defining one handler for each sensor to make the use of wiringPiISR easier
  Each function sends a message to the Central server, to inform about the change
  and also prints to the terminal, for debugging purposes
*/

void presSala(void) {
  char* message = "1";
  sentToCentral(message);
  printf("Presença Sala\n");
}

void presCozinha(void) {
  char* message = "2";
  sentToCentral(message);
  printf("Presença Cozinha\n");
}

void kitchenDoor(void) {
  char* message = "3";
  sentToCentral(message);
  printf("Porta Cozinha\n");
}

void kitchenWindow(void) {
  char* message = "4";
  sentToCentral(message);
  printf("Janela Cozinha\n");
}

void salaDoor(void) {
  char* message = "5";
  sentToCentral(message);
  printf("Porta Sala\n");
}

void salaWindow(void) {
  char* message = "6";
  sentToCentral(message);
  printf("Janela sala\n");
}

void roomOneWindow(void) {
  char* message = "7";
  sentToCentral(message);
  printf("Janela Quarto 01\n");
}

void roomTwoWindow(void) {
  char* message = "8";
  sentToCentral(message);
  printf("Janela Quarto 02\n");

}

void* handleGPIO() {
  /*
    Used to interact with all sensors
  */

  // looping through all sensors and using wiringPiISR to interact with them, also attaching
  // the handler functions which will be called upon any changes 
  int sensors[] = {PRES1, PRES2, ABR1, ABR2, ABR3, ABR4, ABR5, ABR6};
  void (*handlers[])()  = {presSala, presCozinha, kitchenDoor, kitchenWindow, 
                    salaDoor, salaWindow, roomOneWindow, roomTwoWindow};

  for(int i =0; i < sizeof(sensors)/sizeof(sensors[0]) ; i++){
      pinMode(sensors[i], OUTPUT);
      wiringPiISR(sensors[i], INT_EDGE_BOTH, handlers[i]);
  }

  for(;;) {
    sleep(1);
  }
}

void setAllOff() {

  //Turning off all devices

  pinMode(LAMP1, OUTPUT);
  digitalWrite(LAMP1, LOW);

  pinMode(LAMP2, OUTPUT);
  digitalWrite(LAMP2, LOW);

  pinMode(LAMP3, OUTPUT);
  digitalWrite(LAMP3, LOW);

  pinMode(LAMP4, OUTPUT);
  digitalWrite(LAMP4, LOW);

  pinMode(AR1, OUTPUT);
  digitalWrite(AR1, LOW);

  pinMode(AR2, OUTPUT);
  digitalWrite(AR2, LOW);
}
