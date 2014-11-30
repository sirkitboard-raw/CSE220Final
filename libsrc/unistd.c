#include "unistd.h"
#include "lib.h"

#define EXEC_BUFFER_SIZE 2048

int exec(const char* path) {
  char buffer[EXEC_BUFFER_SIZE];
  int ret;
  int fp = open(path,0,0);
  if(!(fp<0)) {
    read(fp, &buffer, EXEC_BUFFER_SIZE);
    ret = load(buffer);
  }
  return ret;
}
