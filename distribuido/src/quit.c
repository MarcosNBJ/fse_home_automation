#include "quit.h"

void quit() {
  //shuts every gpio device off, and exits
  printf("Shutting everything off and exiting");
  setAllOff();
  exit(0);
}