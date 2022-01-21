#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "weatherJson.h"

bool DEBUG_PARSE_FLAG = !true;

char response[JSON_SIZE] = {0};
char buffer[JSON_SIZE] = {0};
int jsonSize = 0;
bool loadJson = !true;

void jsonParse(Json* jsonStr, Position* position, Current* currentWeather, Minutely* weatherMinutely,Hourly* weatherHourly,Daily* weatherDaily);
void init(Json* jsonStr, Position* position, Current* currentWeather,
          Minutely* weatherMinutely,Hourly* weatherHourly,Daily* weatherDaily) {
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
    jsonStr->string[i] = response[i];
  }
  jsonParse(jsonStr, position, currentWeather, weatherMinutely, weatherHourly, weatherDaily);
}

void offFileLoader() {loadJson = false;}
void onFileLoader() {loadJson = false;}

int getJsonSize(Json* jsonStr) {
  if (jsonSize == 0) {
    for (int i = 0; i < sizeof(jsonStr->string) && jsonStr->string[i] != '\0'; ++i) {
      jsonSize++;
    }
  }
  return jsonSize;
}

void clearValues(Position* position, Current* currentWeather, Minutely* weatherMinutely,Hourly* weatherHourly,Daily* weatherDaily) {
  position->lat = 0;
  position->lon = 0;
  position->timezone_offset = 0;
  for (int i = 0; i < sizeof(position->timezone); ++i) {
    position->timezone[i] = '\0';
  }
}

void jsonParse(Json* jsonStr, Position* position, Current* currentWeather, Minutely* weatherMinutely,Hourly* weatherHourly,Daily* weatherDaily) {
  char keys[3][JSON_HEADERS_SIZE] = {0};
  char values[3][JSON_VALUES_SIZE] = {0};
  int keyWriteIndex = 0, valueWriteIndex = 0;
  bool inArray = false;
  bool readKey = false;
  bool readValue = false;
  bool readNumber = false;
  int cursorPosition = 0;
  int openCurlyBracketsCount = 0;
  int deepLvl = 0;
  clearValues(position, currentWeather, weatherMinutely, weatherHourly, weatherDaily);
  for (int i = 0; i < getJsonSize(jsonStr) - 3; ++i) {
    buffer[i] = jsonStr->string[i];
    switch (jsonStr->string[i]) {
      case '{':
        openCurlyBracketsCount++;
        deepLvl++;
        valueWriteIndex = 0;
        keyWriteIndex = 0;
        memset(values[deepLvl], 0, sizeof(values[deepLvl]));
        memset(keys[deepLvl], 0, sizeof(keys[deepLvl]));
        break;
      case '}':
        openCurlyBracketsCount--;
        deepLvl--;
        valueWriteIndex = 0;
        keyWriteIndex = 0;
        memset(values[deepLvl], 0, sizeof(values[deepLvl]));
        memset(keys[deepLvl], 0, sizeof(keys[deepLvl]));
        break;
      case '\"':
        if (jsonStr->string[i-1] == ':') {
          if (jsonStr->string[i-2] == '\"') {
            readKey = false;
            readValue = true;
            keyWriteIndex = 0;
//            memset(keys[deepLvl], 0, sizeof(keys[deepLvl]));
          }
        }
        if (jsonStr->string[i-1] == ',' || jsonStr->string[i-1] == '{' || jsonStr->string[i-1] == '[') {
          readKey = true;
          readValue = false;
          valueWriteIndex = 0;
          memset(values[deepLvl], 0, sizeof(values[deepLvl]));
        }
        break;
      case ':':
//        if (jsonStr->string[i + 1] == '{' || jsonStr->string[i + 2] == '{') {deepLvl++;}
        switch (jsonStr->string[i - 1]) {
          case '\"':
            readKey = false;
            keyWriteIndex = 0;
//            memset(keys[deepLvl], 0, sizeof(keys[deepLvl]));
            break;
        }
        break;
      case ',':
        readValue = false;
        readNumber = false;
        keyWriteIndex = 0;
        valueWriteIndex = 0;
        memset(values[deepLvl], 0, sizeof(values[deepLvl]));
        memset(keys[deepLvl], 0, sizeof(keys[deepLvl]));
        break;
      case '[':
        inArray = true;
        readKey = false;
        readValue = false;
        valueWriteIndex = 0;
        keyWriteIndex = 0;
        memset(values[deepLvl], 0, sizeof(values[deepLvl]));
        memset(keys[deepLvl], 0, sizeof(keys[deepLvl]));
        break;
      default:
        if ((jsonStr->string[i] >= 48 && jsonStr->string[i] <= 57) || (jsonStr->string[i] == 46 && jsonStr->string[i+1] >= 48 && jsonStr->string[i+1] <= 57)) {
          readNumber = true;
        }
    }
    if (DEBUG_PARSE_FLAG) {
      printf("index (%d) -> %d %d %d %d %d \n", i, readKey, readValue, readNumber, inArray, deepLvl);
      printf("index (%d) -> %s\n", i, buffer);
    }
    if (readKey) {
      keys[deepLvl][keyWriteIndex] = jsonStr->string[i];
      keyWriteIndex++;
    }
    if (readValue) {
      values[deepLvl][valueWriteIndex] = jsonStr->string[i];
      valueWriteIndex++;
    }
    if (readNumber) {
      values[deepLvl][valueWriteIndex] = jsonStr->string[i];
      valueWriteIndex++;
    }
    if ((jsonStr->string[i+1] == ',' || jsonStr->string[i+1] == '}') && (values[deepLvl][0] != '\0' && keys[deepLvl][0] != '\0')) {
      printf("key: %s\nvalue: %s\n", keys[deepLvl], values[deepLvl]);
      memset(values[deepLvl], 0, sizeof(values[deepLvl]));
      memset(keys[deepLvl], 0, sizeof(keys[deepLvl]));
    }

  }
}
