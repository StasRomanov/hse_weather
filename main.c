#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
//#include <stdlib.h>
//#include <unistd.h>
#include "api/weatherJson.h"

int main() {
  Json json; Position userPosition; Current currentWeather;
  Minutely weatherMinutely; Hourly weatherHourly; Daily weatherDaily;
//  offFileLoader();
  init(&json, &userPosition, &currentWeather, &weatherMinutely, &weatherHourly, &weatherDaily);
  loadIconAll();
  printf("%s\n", json.string);
  printf("file size %d\n", getJsonSize(&json));
  printf("___Position___\n");
  printf("lat %f\nlon %f\ntimezone %s\ntimezone offset %d\n", userPosition.lat, userPosition.lon, userPosition.timezone, userPosition.timezone_offset);
  printf("___Current___\n");
  printf("dt %ld\nsunrise %ld\nsunset %ld\ntemp %f\nfeels_like %f\npressure %d\nhumidity %d\ndew_point %f\nuvi %d\n"
         "clouds %d\nvisibility %d\nwind_speed %f\nwind_deg %d\nwind_gust %f\nweather_id %d\nweather_main %s\n"
         "weather_description %s\nweather_icon %s\nsnow %f\n", currentWeather.time_sec, currentWeather.sunrise_sec, currentWeather.sunset_sec, currentWeather.temp,
         currentWeather.feels_like, currentWeather.pressure, currentWeather.humidity, currentWeather.dewPoint, currentWeather.uvi,
         currentWeather.clouds, currentWeather.visibility, currentWeather.wind_speed, currentWeather.wind_deg, currentWeather.wind_gust,
         currentWeather.weather_id, currentWeather.weather_main, currentWeather.weather_description, currentWeather.weather_icon, currentWeather.snow);
  printf("___Minutely___\n");
  for (int i = 0; i < 61; ++i) {
    printf("index (%d) -> dt %ld precipitation %d\n", i, weatherMinutely.time_sec[i], weatherMinutely.precipitation[i]);
  }
  for (int i = 0; i < 48; ++i) {
    printf("___Hourly___ ---> (%d)\n", i);
    printf("dt %ld\ntemp %f\nfeels_like %f\npressure %d\nhumidity %d\ndew_point %f\nuvi %d\n"
           "clouds %d\nvisibility %d\nwind_speed %f\nwind_deg %d\nwind_gust %f\nweather_id %d\nweather_main %s\n"
           "weather_description %s\nweather_icon %s\npop %f\n", weatherHourly.time_sec[i], weatherHourly.temp[i],
           weatherHourly.feels_like[i], weatherHourly.pressure[i], weatherHourly.humidity[i], weatherHourly.dewPoint[i], weatherHourly.uvi[i],
           weatherHourly.clouds[i], weatherHourly.visibility[i], weatherHourly.wind_speed[i], weatherHourly.wind_deg[i], weatherHourly.wind_gust[i],
           weatherHourly.weather_id[i], weatherHourly.weather_main, weatherHourly.weather_description, weatherHourly.weather_icon, weatherHourly.pop[i]);
  }
  for (int i = 0; i < 8; ++i) {
    printf("___Daily___ ---> (%d)\n", i);
    printf("dt %ld\n"
           "temp_day %f\ntemp_min %f\ntemp_max %f\ntemp_night %f\ntemp_eve %f\ntemp_morn %f\n"
           "feels_like_day %f\nfeels_like_night %f\nfeels_like_eve %f\nfeels_like_morn %f\n"
           "pressure %d\nhumidity %d\ndew_point %f\n"
           "wind_speed %f\nwind_deg %d\nwind_gust %f\n"
           "weather_id %d\nweather_main %s\nweather_description %s\nweather_icon %s\n"
           "clouds %d\npop %f\nrain (none)\nsnow %f\nuvi %f\n", weatherDaily.time_sec[i], weatherDaily.temp_day[i],
           weatherDaily.temp_min[i], weatherDaily.temp_max[i], weatherDaily.temp_night[i], weatherDaily.temp_eve[i], weatherDaily.temp_morn[i],
           weatherDaily.feels_like_day[i], weatherDaily.feels_like_night[i], weatherDaily.feels_like_eve[i], weatherDaily.feels_like_morn[i],
           weatherDaily.pressure[i], weatherDaily.humidity[i], weatherDaily.dew_point[i],
           weatherDaily.wind_speed[i], weatherDaily.wind_deg[i], weatherDaily.wind_gust[i],
           weatherDaily.weather_id[i], weatherDaily.weather_main, weatherDaily.weather_description, weatherDaily.weather_icon,
           weatherDaily.clouds[i], weatherDaily.pop[i], weatherDaily.snow[i], weatherDaily.uvi[i]);
  }
  return 0;
}
