#include "menu.h"

WINDOW *window;

void showMenu(WINDOW *window, int highlight, char *options[], int n_options) {
	//shows options menu

	int x = 2, y = 2, i;

	box(window, 0, 0);
	for(i = 0; i < n_options; i++) {
		if (i == n_options - 1) {
			wattron(window, COLOR_PAIR(2));
		}
		if (highlight == i + 1) {
			wattron(window, A_REVERSE);
			mvwprintw(window, y, x, "%s", options[i]);
			wattroff(window, A_REVERSE);
		} else {
			mvwprintw(window, y, x, "%s", options[i]);
		}
		if (i == n_options - 1) {
			wattroff(window, COLOR_PAIR(2));
		}
		++y;
	}
	wrefresh(window);
}

void clsMenu(WINDOW *window_param) {
	//clear window

	wclear(window_param);
	wborder(window_param, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');  
	wrefresh(window_param);
	delwin(window_param); 
}

void printDeviceToMenu(Data data) {
	//left side of screen, with devices, alarm and BME info

	wattron(window, COLOR_PAIR(data.devices.lamp1 == 1 ? 3 : 2));
	mvwprintw(window, 2, 17, data.devices.lamp1 == 1 ? "ON " : "OFF");
	wattroff(window, COLOR_PAIR(data.devices.lamp1 == 1 ? 3 : 2));

	wattron(window, COLOR_PAIR(data.devices.lamp2 == 1 ? 3 : 2));
	mvwprintw(window, 3, 17, data.devices.lamp2 == 1 ? "ON " : "OFF");
	wattroff(window, COLOR_PAIR(data.devices.lamp2 == 1 ? 3 : 2));

	wattron(window, COLOR_PAIR(data.devices.lamp3 == 1 ? 3 : 2));
	mvwprintw(window, 4, 17, data.devices.lamp3 == 1 ? "ON " : "OFF");
	wattroff(window, COLOR_PAIR(data.devices.lamp3 == 1 ? 3 : 2));

	wattron(window, COLOR_PAIR(data.devices.lamp4 == 1 ? 3 : 2));
	mvwprintw(window, 5, 17, data.devices.lamp4 == 1 ? "ON " : "OFF");
	wattroff(window, COLOR_PAIR(data.devices.lamp4 == 1 ? 3 : 2));

	wattron(window, COLOR_PAIR(data.devices.ar1 == 1 ? 3 : 2));
	mvwprintw(window, 6, 17, data.devices.ar1 == 1 ? "ON " : "OFF");
	wattroff(window, COLOR_PAIR(data.devices.ar1 == 1 ? 3 : 2));

	wattron(window, COLOR_PAIR(data.devices.ar2 == 1 ? 3 : 2));
	mvwprintw(window, 7, 17, data.devices.ar2 == 1 ? "ON " : "OFF");
	wattroff(window, COLOR_PAIR(data.devices.ar2 == 1 ? 3 : 2));

	wattron(window, COLOR_PAIR(data.devices.alarm == 1 ? 3 : 2));
	mvwprintw(window, 8, 17, data.devices.alarm == 1 ? "ON " : "OFF");
	wattroff(window, COLOR_PAIR(data.devices.alarm == 1 ? 3 : 2));

	wattron(window, COLOR_PAIR(1));
  mvwprintw(window, 11, 2, "TEMPERATURE: %4.2f", data.bme280.temperature);
  mvwprintw(window, 12, 2, "HUMIDITY: %4.2f", data.bme280.humidity);
	wattroff(window, COLOR_PAIR(1));

	wattron(window, COLOR_PAIR(data.devices.playing == 1 ? 3 : 2));
	mvwprintw(window, 14, 2, "ALARM ACTIVE: %s", data.devices.playing == 1 ? "YES " : "NO");
	wattroff(window, COLOR_PAIR(data.devices.playing == 1 ? 3 : 2));

  wrefresh(window);
}

void printSensorToMenu(Sensor sensors) {
	//right side of screen, with sensor states

	mvwprintw(window, 2, 22, "Sensor de Presença Sala");
	wattron(window, COLOR_PAIR(sensors.pres1 == 1 ? 3 : 2));
	mvwprintw(window, 2, 61, sensors.pres1 == 1 ? "ON " : "OFF");
	wattroff(window, COLOR_PAIR(sensors.pres1 == 1 ? 3 : 2));

	mvwprintw(window, 3, 22, "Sensor de Presença Cozinha:");
	wattron(window, COLOR_PAIR(sensors.pres2 == 1 ? 3 : 2));
	mvwprintw(window, 3, 61, sensors.pres2 == 1 ? "ON " : "OFF");
	wattroff(window, COLOR_PAIR(sensors.pres2 == 1 ? 3 : 2));

	mvwprintw(window, 4, 22, "Sensor Porta Cozinha:");
	wattron(window, COLOR_PAIR(sensors.abr1 == 1 ? 3 : 2));
	mvwprintw(window, 4, 61, sensors.abr1 == 1 ? "ON " : "OFF");
	wattroff(window, COLOR_PAIR(sensors.abr1 == 1 ? 3 : 2));

	mvwprintw(window, 5, 22, "Sensor Janela Cozinha:");
	wattron(window, COLOR_PAIR(sensors.abr2 == 1 ? 3 : 2));
	mvwprintw(window, 5, 61, sensors.abr2 == 1 ? "ON " : "OFF");
	wattroff(window, COLOR_PAIR(sensors.abr2 == 1 ? 3 : 2));

	mvwprintw(window, 6, 22, "Sensor Porta Sala:");
	wattron(window, COLOR_PAIR(sensors.abr3 == 1 ? 3 : 2));
	mvwprintw(window, 6, 61, sensors.abr3 == 1 ? "ON " : "OFF");
	wattroff(window, COLOR_PAIR(sensors.abr3 == 1 ? 3 : 2));

	mvwprintw(window, 7, 22, "Sensor Janela Sala:");
	wattron(window, COLOR_PAIR(sensors.abr4 == 1 ? 3 : 2));
	mvwprintw(window, 7, 61, sensors.abr4 == 1 ? "ON " : "OFF");
	wattroff(window, COLOR_PAIR(sensors.abr4 == 1 ? 3 : 2));

	mvwprintw(window, 8, 22, "SensorJanela Quarto 01:");
	wattron(window, COLOR_PAIR(sensors.abr5 == 1 ? 3 : 2));
	mvwprintw(window, 8, 61, sensors.abr5 == 1 ? "ON " : "OFF");
	wattroff(window, COLOR_PAIR(sensors.abr5 == 1 ? 3 : 2));

	mvwprintw(window, 9, 22, "Sensor Janela Quarto 02:");
	wattron(window, COLOR_PAIR(sensors.abr6 == 1 ? 3 : 2));
	mvwprintw(window, 9, 61, sensors.abr6 == 1 ? "ON " : "OFF");
	wattroff(window, COLOR_PAIR(sensors.abr6 == 1 ? 3 : 2));

  wrefresh(window);
}

void* optionsHandler() {
	//handles user chosen options

	//available options
	char *options[] = {
		"LAMP 01 COZ:",
		"LAMP 02 SAL:",
		"LAMP 03 Q01:",
		"LAMP 04 Q02:",
		"AR CONDI 01:",
		"AR CONDI 02:",
		"ALARME:",
		"EXIT",
	};

	int startx = 0;
	int starty = 0;
	int n_options = sizeof(options) / sizeof(char *);

	int highlight = 1;
	int option = 0;
	int c;

	initscr();
	start_color(); 
	clear();
	noecho();
	cbreak();
	curs_set(0);
	init_pair(1, COLOR_YELLOW, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
     
	window = newwin(HEIGHT, WIDTH, starty, startx);
	keypad(window, TRUE);
	refresh();

	initDevicesAndSensors();

	do {
		showMenu(window, highlight, options, n_options);
		c = wgetch(window);

		switch(c) {
			case KEY_UP:
				if(highlight == 1)
					highlight = n_options;
				else
					--highlight;
				break;
			case KEY_DOWN:
				if(highlight == n_options)
					highlight = 1;
				else
					++highlight;
				break;
			case 10:    
				option = highlight;

				Device devices = getDevices();

				//if the user has chosen to alter any device
				//we make the state change and log the info
				if (option == 1) {
					devices.lamp1 = devices.lamp1 == 1 ? 0 : 1;
					appentToLog("LAMP01",devices.lamp1);
				}

				if (option == 2) {
					devices.lamp2 = devices.lamp2 == 1 ? 0 : 1;
					appentToLog("LAMP02",devices.lamp2);
				}

				if (option == 3) {
					devices.lamp3 = devices.lamp3 == 1 ? 0 : 1;
					appentToLog("LAMP03",devices.lamp3);
				}

				if (option == 4) {
					devices.lamp4 = devices.lamp4 == 1 ? 0 : 1;
					appentToLog("LAMP04",devices.lamp4);

				}

				if (option == 5) {
					devices.ar1 = devices.ar1 == 1 ? 0 : 1;
					appentToLog("AR01",devices.ar1);
				}

				if (option == 6) {
					devices.ar2 = devices.ar2 == 1 ? 0 : 1;
					appentToLog("AR02",devices.ar2);
				}

				if (option == 7) {
					devices.alarm = devices.alarm == 1 ? 0 : 1;
					appentToLog("ALARM",devices.alarm);
				}

				updateDevices(devices);

				if (option == 8) {
					//EXIT option
					quit();
				}

				break;
			default:
				refresh();
				break;
		}
	} while(1);

	return NULL;
}
