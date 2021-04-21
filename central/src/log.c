#include "log.h"

const char *getTimestamp(){
    //Returns the current datetime, following the format dd-mm-yyyy-H:M:S

    static char timestamp[20];
    time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);
    sprintf(timestamp, "%02d-%02d-%02d-%02d:%02d:%02d", tm.tm_mday, tm.tm_mon + 1, 
      tm.tm_year + 1900,tm.tm_hour,tm.tm_min,tm.tm_sec);
    return timestamp;
}  


void createCSV() {
  //Creates the log file with header, overwriting if a previous one exists 
  FILE *file = fopen("log.csv", "w");
  fprintf(file, "DATETIME, DEVICE, ACTION\n");
  fclose(file);
}

void appentToLog(char *device, int status) {
  // append received info to log
  FILE *file = fopen("log.csv", "a");
  char *action = status == 1 ? "TURN ON" : "TURN OFF";
  fprintf(file, "%s,%s,%s\r\n", getTimestamp(), device, action);
  fclose(file);
}
