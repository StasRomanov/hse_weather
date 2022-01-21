#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "api/weatherJson.h"

int main() {
  Json json = {}; Position userPosition = {}; Current currentWeather = {};
  Minutely weatherMinutely ={}; Hourly weatherHourly = {}; Daily weatherDaily = {};
  offFileLoader();
  init(&json, &userPosition, &currentWeather, &weatherMinutely, &weatherHourly, &weatherDaily);
  printf("%s\n", json.string);
  printf("file size %d\n", getJsonSize(&json));
//  jsonParse(&json, &userPosition, &currentWeather, &weatherMinutely, &weatherHourly, &weatherDaily);
  printf("lat %f\nlon %f\ntimezone %s\ntimezone offset %d\n", userPosition.lat, userPosition.lon, userPosition.timezone, userPosition.timezone_offset);
  return 0;
}
