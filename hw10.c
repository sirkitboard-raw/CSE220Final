#include "lib.h"
#include "stdio.h"
#include "string.h"
#define INPUT_BUFFER 2048

int main() {
  char buffer[INPUT_BUFFER];
  char tempBuffer[INPUT_BUFFER];
  int ret = 0;
  while(1) {
    printf("> ");
    fgets(INPUT_BUFFER, &buffer);
    if(strcmp(buffer,"help\n")) {
      printf("List of utilities\nhelp Displays this help menu\nexit Terminates execution of the shell\necho Simple utility that writes to stdout\n");
    }
    else if(strcmp(buffer,"exit\n")) {
      return EXIT_SUCCESS;
    }
    strncpy()
    if ()
  }
  return EXIT_FAILURE;
}
