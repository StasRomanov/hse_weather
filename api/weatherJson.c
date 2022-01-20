#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "weatherJson.h"

void init(Weather* weather) {
  system("cd ../ && mkdir storage && cd ./storage && mkdir json");
//  system("clear");
  system("curl " JSON_LINK " > ../storage/json/weatherCurrent.json");
  system("clear");
  char response[JSON_SIZE] = {0};
  freopen("../storage/json/weatherCurrent.json","r",stdin);
  gets(response);
  system("clear");
  fclose(stdin);
  for (int i = 0; response[i] != '\0'; ++i) {
    weather->json[i] = response[i];
  }
}

void getJsonStr(Weather* weather) {
  printf("%s\n", weather->json);
//  printf("%s", JSON_LINK);
}