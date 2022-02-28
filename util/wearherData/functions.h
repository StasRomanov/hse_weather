#ifndef HSE_WEATHER_FUNCTIONS_H
#define HSE_WEATHER_FUNCTIONS_H


#include "../../api/weatherJson.h"

void printJsonLink();
void printJsonStr(Json* jsonStr);
void printJsonStrSize(Json* jsonStr);
void printLocationInfo(Position* userPosition);
void printCurrentWeatherInfo(Current* currentWeather);
void printMinutelyWeatherInfo(Minutely* weatherMinutely);
void printHourlyWeatherInfo(Hourly* weatherHourly);
void printDailyWeatherInfo(Daily* weatherDaily);

#endif //HSE_WEATHER_FUNCTIONS_H
