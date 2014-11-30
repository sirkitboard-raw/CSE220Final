#ifndef STDIO_H
  #define STDIO_H
  #if !defined(NULL)
    #define NULL ((void*)0)
  #endif
  char* fgets(int size, char *buffer);
  void printf(const char* fmt, ...);
#endif
