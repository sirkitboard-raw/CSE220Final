#include "lib.h"

void putoctal(int a) {
  int i,temp;
  temp = a >> 30;
  temp = temp & 0x3;
  putint(temp);
  a = a << 2;
  for(i=0;i<10;i++) {
    temp = a & 0xE0000000;
    temp = temp >>29;
    temp = temp & 0x7;
    putint(temp);
    a = a << 3;
  }
}
