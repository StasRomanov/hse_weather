#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "api/weatherJson.h"
#include "util/wearherData/functions.h"

int main() {
  Json json; Position userPosition; Current currentWeather;
  Minutely weatherMinutely; Hourly weatherHourly; Daily weatherDaily;
  set_OSX_Mode();
//  offFileLoader();
//  offImgLoader();
  init(&json, &userPosition, &currentWeather, &weatherMinutely, &weatherHourly, &weatherDaily);
  loadIconAll();
  return 0;
}
