#include "quit.h"

void quit() {
  //Closes I2C, shuts every gpio device off, and exits
  printf("Shutting everything off and exiting");
  closeI2C();
  setAllOff();
  exit(0);
}