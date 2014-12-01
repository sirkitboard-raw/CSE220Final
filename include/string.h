#include "stddef.h"

#ifndef STRING_H
  #define STRING_H
  #if !defined(NULL)
    #define NULL ((void*)0)
  #endif


  /**
   * Calculates the length of a '\0' terminated string.
   * (the null character is not part of the length)
   * @param str Pointer to a '\0' terminated string.
   * @return Returns the length of the string.
   */
  size_t strlen(const char *str);

  /**
   * Determines if two strings are exactly equal to each other.
   * @param str1 Pointer to a '\0' terminated string.
   * @param str2 Pointer to a '\0' terminated string.
   * @return Returns 1 if equal, else 0.
   */
  int strcmp(const char *str1, const char *str2);

  /**
   * Copies the string from src into dst.
   * @param dest Buffer to copy into.
   * @param src String to copy.
   * @param n Non-negative maximum about of bytes that can be copied from src.
   * @return Returns the dst pointer.
   */
  char* strncpy(char *dst, const char *src, size_t n);


#endif
