#include "server.h"

void* receiveFromCentral() {
  /*
    Receiving commands from the central server
  */
  struct sockaddr_in server, client;

	int serverid = socket(AF_INET, SOCK_STREAM, 0);

	memset(&server, '0', sizeof(server));

	server.sin_family = AF_INET;
	server.sin_addr.s_addr = htonl(INADDR_ANY);
	server.sin_port = htons(SERVER_DISTRIBUTED_PORT);

	bind(serverid, (struct sockaddr*) &server, sizeof(server));

	if (listen(serverid, 10) == -1) {
		printf("ERROR");
		exit(1);
	}

  while (1) {
	  unsigned int len = sizeof(client);
	  int clientid = accept(serverid, (struct sockaddr*) &client, &len);

    char buffer[16];
	  int size = recv(clientid, buffer, 16, 0);

    if (size < 0) {
      printf("ERROR");
      exit(1);
    }
    
    buffer[15] = '\0';
		
    int command;
    sscanf(buffer, "%d", &command);


    // 1 means turning on a lamp or ar condicioner
    if (command == 1) {
      printf("Alterando estado de dispositivo\n");
      int item;
      int status;
      sscanf(buffer, "%d %d %d", &command, &item, &status);
      toggleDevice(item, status);
      char buf[2];
      snprintf(buf, 2, "%d", 1);
      int size = strlen(buf);
      if (send(clientid, buf, size, 0) != size) {
        printf("Error: Send failed\n");
      }
    }

    // 2 means temperature and humidity reading
    if (command == 2) {
      printf("Coletando dados de temperatura e humidade\n");
      char buf[16];
      snprintf(buf, 16, "%d %4.2f %4.2f", 2, getTemperature(),getHumidity());
      int size = strlen(buf);
      printf("Enviando dados de temperatura e humidade para o servidor central\n");
      if (send(clientid, buf, size, 0) != size) {
        printf("Error: Send failed\n");
      }
    }
		
		close(clientid);
  }

	close(serverid);
}

void sentToCentral(char *message) {
  /*
    Used to send information to central server
    such as changes on sensors
  */

	struct sockaddr_in client;

  int socketid = socket(AF_INET, SOCK_STREAM, 0);
  if (socketid == -1) {
    printf("Could not create a socket!\n");
    exit(1);
  }

  client.sin_family = AF_INET;
  client.sin_addr.s_addr = inet_addr(SERVER_CENTRAL_IP);
  client.sin_port = htons(SERVER_CENTRAL_PORT);

  if (connect(socketid, (struct sockaddr*) &client, sizeof(client)) < 0) {
    printf("Error: Connection failed\n");
    exit(1);
  }

  int size = strlen(message);
  if (send(socketid, message, size, 0) != size) {
		printf("Error: Send failed\n");
    exit(1);
  }

  close(socketid);
}
