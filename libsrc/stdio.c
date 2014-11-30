#include "lib.h"

char* fgets(int size, char *buffer) {
  return readstring(buffer, size);
}
