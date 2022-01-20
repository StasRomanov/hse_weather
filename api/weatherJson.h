#ifndef LOADER_WEATHERJSON_H
#define LOADER_WEATHERJSON_H

#define JSON_SIZE 20000
#define JSON_LINK "\"https://api.openweathermap.org/data/2.5/forecast?id=524901&appid=1b6f09a641acd38d7c029629e51700b6\""

typedef struct {
  char json[JSON_SIZE];
}Weather;

void init(Weather* weather);
void getJsonStr(Weather* weather);



#endif //LOADER_WEATHERJSON_H
