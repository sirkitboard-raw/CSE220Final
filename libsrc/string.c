#include "stddef.h"
#include "string.h"

/**
 * Calculates the length of a '\0' terminated string.
 * (the null character is not part of the length)
 * @param str Pointer to a '\0' terminated string.
 * @return Returns the length of the string.
 */
size_t strlen(const char *str) {
  //TODO: String lengh returns size + 1
  size_t ctr = 0;
  int incr = 0;
  while (*(str+incr) != '\0') {
    ctr++;
    incr+=sizeof(char);
  }
  return ctr;
}

/**
 * Determines if two strings are exactly equal to each other.
 * @param str1 Pointer to a '\0' terminated string.
 * @param str2 Pointer to a '\0' terminated string.
 * @return Returns 1 if equal, else 0.
 */
int strcmp(const char *str1, const char *str2){
  int i;
  int ret=1;
  if(strlen(str1)!=strlen(str2)) {
    return 0;
  }
  else {
    for(i=0;i<strlen(str1);i=i+sizeof(char)) {
      if(*(str1+i)!=*(str2+i)) {
        ret = 0;
        break;
      }
    }
  }
  return ret;
}
