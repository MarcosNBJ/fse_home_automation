#include "quit.h"

void quit() {
  //shuts off the ncurses screen and exits

  refresh();
  endwin();
  printf("Shutting down");
  exit(0);
}