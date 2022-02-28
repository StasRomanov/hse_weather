#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "api/weatherJson.h"
#include "util/wearherData/functions.h"
#include "system/setup.h"

int main() {
  Json json; Position userPosition; Current currentWeather;
  Minutely weatherMinutely; Hourly weatherHourly; Daily weatherDaily;
  setupAPI();
  init(&json, &userPosition, &currentWeather, &weatherMinutely, &weatherHourly, &weatherDaily);
  // use this if you want load icons
//  loadIconAll();
  printJsonLink();
  printJsonStr(&json);
  printJsonStrSize(&json);
  printLocationInfo(&userPosition);
  printCurrentWeatherInfo(&currentWeather);
  printMinutelyWeatherInfo(&weatherMinutely);
  printHourlyWeatherInfo(&weatherHourly);
  printDailyWeatherInfo(&weatherDaily);
  return 0;
}
