#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "weatherJson.h"

char response[JSON_SIZE] = {0};
int cursorPosition = 0;
int openCurlyBracesCount = 0;
int closeCurlyBracesCount = 0;
int jsonSize = 0;
bool loadJson = true;

void init(Json* weather) {
  if (loadJson) {
    system("cd ../ && mkdir storage && cd ./storage && mkdir json");
    system("curl "JSON_LINK" > ../storage/json/weatherCurrent.json");
    system("clear");
  }
  freopen("../storage/json/weatherCurrent.json","r",stdin);
  gets(response);
  system("clear");
  fclose(stdin);
  for (int i = 0; response[i] != '\0'; ++i) {
    weather->string[i] = response[i];
  }
}

void offFileLoader() {loadJson = false;}
void onFileLoader() {loadJson = false;}

void parseJson() {

}

void getJsonSize() {

}