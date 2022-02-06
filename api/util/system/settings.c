#include "settings.h"
#include <stdbool.h>

bool OSX_API = false;
bool WIN_API = false;
bool RELEASE_MODE = false;

void set_OSX_Mode() {
  OSX_API = true;
  WIN_API = false;
}

void set_WINDOWS_Mode() {
  OSX_API = false;
  WIN_API = true;
}

bool get_OSX_status() {
  return OSX_API ? true : false;
}

bool get_WINDOWS_status() {
  return WIN_API ? true : false;
}

bool get_RELEASE_status() {
  return RELEASE_MODE ? true : false;
}
