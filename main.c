#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "api/weatherJson.h"

int main() {
//  system("cd ../js && node ./main.js");
//  char resolve[10000] = {0};
//  system("cd ../ && mkdir storage && cd ./storage && mkdir json");
//  system("curl \"https://api.openweathermap.org/data/2.5/weather?lat=56.317492&lon=44.067198&appid=1b6f09a641acd38d7c029629e51700b6\" > ../storage/json/weatherCurrent.json");
//  freopen("../storage/json/weatherCurrent.json","r",stdin);
//  gets(resolve);
//  printf("%s\n", resolve);
//  fclose(stdin);
  Weather weather = {};
//  for (int i = 0; resolve[i] != '\0'; ++i) {
//    weather.json[i] = resolve[i];
//  }
  init(&weather);
  getJsonStr(&weather);
  return 0;
}







