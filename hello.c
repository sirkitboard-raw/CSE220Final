#include "lib.h"
#include "string.h"
#include "unistd.h"

int main(void) {
  int ret = exec("/usr/local/bin/shellbin/rand");
  return ret;
}
