#include "server.h"

void* receiveCommands() {
  /*
    Used to receive data from the distribuited servers
    such as sensor changes
  */

  struct sockaddr_in server, client;

	int serverid = socket(AF_INET, SOCK_STREAM, 0);

	memset(&server, '0', sizeof(server));

	server.sin_family = AF_INET;
	server.sin_addr.s_addr = htonl(INADDR_ANY);
	server.sin_port = htons(SERVER_CENTRAL_PORT);

	bind(serverid, (struct sockaddr*) &server, sizeof(server));

	if (listen(serverid, 10) == -1) {
		quit();
	}

  while (1) {
	  unsigned int len = sizeof(client);
	  int clientid = accept(serverid, (struct sockaddr*) &client, &len);

    char buffer[16];
	  int size = recv(clientid, buffer, 16, 0);

    if (size < 0) {
      quit();
    }
    
    buffer[15] = '\0';

		int command;
		sscanf(buffer, "%d", &command);

    //sending new sensor info to handler
    sensorsHandler(command);
		
		close(clientid);
  }

	close(serverid);
}

int sendCommands(int item, int status) {
  /*
    Used to send commands to distributed servers
    such as to change the state of a device
  */
  struct sockaddr_in client;

  int socketid = socket(AF_INET, SOCK_STREAM, 0);
  if (socketid == -1) {
    quit();
  }

  client.sin_family = AF_INET;
  client.sin_addr.s_addr = inet_addr(SERVER_DISTRIBUTED_IP);
  client.sin_port = htons(SERVER_DISTRIBUTED_PORT);

  if (connect(socketid, (struct sockaddr*) &client, sizeof(client)) < 0) {
    quit();
  }

  char buf[6];
  snprintf(buf, 6, "%d %d %d", 1, item, status);
  int size = strlen(buf);
  if (send(socketid, buf, size, 0) != size) {
    quit();
  }

  char buffer[16];
  int size_rec = recv(socketid, buffer, 16, 0);
  if (size_rec < 0) {
    quit();
  }

  buffer[15] = '\0';

  int res;
  sscanf(buffer, "%d", &res);

  close(socketid);

  return res;
}

BME280 readBMEInfo() {
  /*
    Used to request new temperature and humidty information
    from the distributed servers
  */

  struct sockaddr_in client;

  BME280 bme280;
  bme280.temperature = 0;
  bme280.humidity = 0;

  int socketid = socket(AF_INET, SOCK_STREAM, 0);
  if (socketid == -1) {
    return bme280;
  }

  client.sin_family = AF_INET;
  client.sin_addr.s_addr = inet_addr(SERVER_DISTRIBUTED_IP);
  client.sin_port = htons(SERVER_DISTRIBUTED_PORT);

  if (connect(socketid, (struct sockaddr*) &client, sizeof(client)) < 0) {
    return bme280;
  }

  char buf[2];
  snprintf(buf, 2, "%d", 2);
  int size = strlen(buf);
  if (send(socketid, buf, size, 0) != size) {
    close(socketid);
    return bme280;
  }

  char buffer[16];
  int size_rec = recv(socketid, buffer, 16, 0);
  if (size_rec < 0) {
    close(socketid);
    return bme280;
  }
    
  buffer[15] = '\0';
	
  int command;
  double temperature;
  double humidity;
  sscanf(buffer, "%d %lf %lf", &command, &temperature, &humidity);
  bme280.temperature = temperature;
  bme280.humidity = humidity;

  close(socketid);

  return bme280;
}
