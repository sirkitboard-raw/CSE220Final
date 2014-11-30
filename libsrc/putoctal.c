#include "lib.h"

void putoctal(int a) {
  int rem;
  if(a==0){
    return;
  }
  rem = a%8;
  putoctal(a/8);
  putint(rem);
}
