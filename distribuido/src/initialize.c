#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"

int output_devices[5];
int number_of_devices;
char ip[13];
int port;

void init_device_info_from_json(const char * const devices_json)
{
    const cJSON *item = NULL;
    const cJSON *outputs = NULL;
    const cJSON *name = NULL;


    cJSON *devices = cJSON_Parse(devices_json);
    if (devices == NULL)
    {
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL)
        {
            fprintf(stderr, "Error before: %s\n", error_ptr);
        }
        return;
    }

    name = cJSON_GetObjectItemCaseSensitive(devices, "nome");
    printf("Analisando \"%s\"\n", name->valuestring);
    
    cJSON *ip_json = cJSON_GetObjectItemCaseSensitive(devices, "ip");
    strcpy(ip,ip_json->valuestring);

    cJSON *porta_json = cJSON_GetObjectItemCaseSensitive(devices, "porta");
    port = porta_json->valueint;

    printf("IP: %s e Porta: %d\n", ip, port);

    outputs = cJSON_GetObjectItemCaseSensitive(devices, "outputs");

    number_of_devices = 0;
    cJSON_ArrayForEach(item, outputs)
    {

        cJSON *tag = cJSON_GetObjectItemCaseSensitive(item, "tag");
        cJSON *gpio = cJSON_GetObjectItemCaseSensitive(item, "gpio");

        printf("%s na gpio %d\n", tag->valuestring, gpio->valueint);

        output_devices[number_of_devices] = gpio->valueint;
        number_of_devices += 1;
    }

}

int getNumberOfDevices(){
  return number_of_devices;
}

int *getOutputDevices(){
  return output_devices;
}

char *getIP(){
  return ip;
}

int getPort(){
  return port;
}