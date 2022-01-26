#ifndef LOADER_WEATHER_JSON_H
#define LOADER_WEATHER_JSON_H

#define IMG_SIZE_NORMAL "2X"
#define IMG_SIZE_BIG "4X"

#define JSON_SIZE 25000
#define JSON_LANG "en"
#define JSON_LAT "56.317492"
#define JSON_LON "44.067198"
#define JSON_UNITS "metric"
#define JSON_KEY "1b6f09a641acd38d7c029629e51700b6"
#define JSON_TYPE "onecall"
#define JSON_LINK "\"https://api.openweathermap.org/data/2.5/"JSON_TYPE"?lat="JSON_LAT"&units="JSON_UNITS"&lon="JSON_LON"&lang="JSON_LANG"&appid="JSON_KEY"\""

#define JSON_TXT_FIELD_SIZE 40
#define JSON_MIN_FIELD_LENGTH 61
#define JSON_HOURLY_FIELD_LENGTH 48
#define JSON_DAILY_FIELD_LENGTH 8
// потом может пропишу всем разные (no)

#define JSON_HEADERS_SIZE 20
#define JSON_VALUES_SIZE 40
#define ICONS_ARRAY_LEN 15

typedef struct {
  char string[JSON_SIZE];
}Json;

typedef struct {
  char timezone[JSON_TXT_FIELD_SIZE];
  float lat, lon;
  int timezone_offset;
}Position;

typedef struct {
  long time_sec, sunrise_sec, sunset_sec;
  float temp, feels_like, wind_gust, wind_speed, dewPoint, snow;
  int pressure, humidity, uvi, clouds, visibility, wind_deg;
  int weather_id;
  char weather_main[JSON_TXT_FIELD_SIZE], weather_description[JSON_TXT_FIELD_SIZE], weather_icon[JSON_TXT_FIELD_SIZE];
}Current;

typedef struct {
  long time_sec[JSON_MIN_FIELD_LENGTH];
  int precipitation[JSON_MIN_FIELD_LENGTH];
}Minutely;

typedef struct {
  long time_sec[JSON_HOURLY_FIELD_LENGTH];
  float temp[JSON_HOURLY_FIELD_LENGTH], feels_like[JSON_HOURLY_FIELD_LENGTH], wind_gust[JSON_HOURLY_FIELD_LENGTH],
  pop[JSON_HOURLY_FIELD_LENGTH],dewPoint[JSON_HOURLY_FIELD_LENGTH], wind_speed[JSON_HOURLY_FIELD_LENGTH];
  int pressure[JSON_HOURLY_FIELD_LENGTH], humidity[JSON_HOURLY_FIELD_LENGTH],
  uvi[JSON_HOURLY_FIELD_LENGTH], clouds[JSON_HOURLY_FIELD_LENGTH], visibility[JSON_HOURLY_FIELD_LENGTH],
  wind_deg[JSON_HOURLY_FIELD_LENGTH];
  int weather_id[JSON_HOURLY_FIELD_LENGTH];
  char weather_main[JSON_TXT_FIELD_SIZE*JSON_HOURLY_FIELD_LENGTH],
  weather_description[JSON_TXT_FIELD_SIZE*JSON_HOURLY_FIELD_LENGTH], weather_icon[JSON_TXT_FIELD_SIZE*JSON_HOURLY_FIELD_LENGTH];
}Hourly;

typedef struct {
  long time_sec[JSON_DAILY_FIELD_LENGTH], sunrise_sec[JSON_DAILY_FIELD_LENGTH], sunset_sec[JSON_DAILY_FIELD_LENGTH],
  moonrise_sec[JSON_DAILY_FIELD_LENGTH], moonset_sec[JSON_DAILY_FIELD_LENGTH];
  float temp_day[JSON_DAILY_FIELD_LENGTH], temp_min[JSON_DAILY_FIELD_LENGTH], temp_max[JSON_DAILY_FIELD_LENGTH],
  temp_night[JSON_DAILY_FIELD_LENGTH], temp_eve[JSON_DAILY_FIELD_LENGTH], temp_morn[JSON_DAILY_FIELD_LENGTH],
  moon_phase[JSON_DAILY_FIELD_LENGTH];
  float feels_like_day[JSON_DAILY_FIELD_LENGTH], feels_like_night[JSON_DAILY_FIELD_LENGTH],
  feels_like_eve[JSON_DAILY_FIELD_LENGTH], feels_like_morn[JSON_DAILY_FIELD_LENGTH];
  int pressure[JSON_DAILY_FIELD_LENGTH], humidity[JSON_DAILY_FIELD_LENGTH], wind_deg[JSON_DAILY_FIELD_LENGTH],
  clouds[JSON_DAILY_FIELD_LENGTH], weather_id[JSON_DAILY_FIELD_LENGTH];
  float dew_point[JSON_DAILY_FIELD_LENGTH], wind_speed[JSON_DAILY_FIELD_LENGTH], wind_gust[JSON_DAILY_FIELD_LENGTH],
  pop[JSON_DAILY_FIELD_LENGTH], snow[JSON_DAILY_FIELD_LENGTH], uvi[JSON_DAILY_FIELD_LENGTH];
  char weather_main[JSON_TXT_FIELD_SIZE*JSON_DAILY_FIELD_LENGTH],
  weather_description[JSON_TXT_FIELD_SIZE*JSON_DAILY_FIELD_LENGTH], weather_icon[JSON_TXT_FIELD_SIZE*JSON_DAILY_FIELD_LENGTH];
}Daily;

//структура с alerts отсутствует поскольку сложно определить размеры как ее так и текста
//будет добавлена потом


void init(Json* jsonStr, Position* position, Current* currentWeather,
          Minutely* weatherMinutely,Hourly* weatherHourly,Daily* weatherDaily);
void offFileLoader();
void onFileLoader();
int getJsonSize(Json* jsonStr);
void loadIconAll();
void offImgLoader();
void onImgLoader();
//void jsonParse(Json* jsonStr, Position* position, Current* currentWeather, Minutely* weatherMinutely,Hourly* weatherHourly,Daily* weatherDaily);



#endif //LOADER_WEATHER_JSON_H
