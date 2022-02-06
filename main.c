#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "api/weatherJson.h"
#include "util/wearherData/functions.h"

int main() {
  Json json; Position userPosition; Current currentWeather;
  Minutely weatherMinutely; Hourly weatherHourly; Daily weatherDaily;
  set_WINDOWS_Mode();
  init(&json, &userPosition, &currentWeather, &weatherMinutely, &weatherHourly, &weatherDaily);
//  loadIconAll();
  return 0;
}
