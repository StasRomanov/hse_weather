#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "api/weatherJson.h"

int main() {
  Json json = {};
  offFileLoader();
  init(&json);
  printf("%s", json.string);
  return 0;
}
