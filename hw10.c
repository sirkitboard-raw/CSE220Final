#include "lib.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
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
    strncpy(tempBuffer, buffer, 4);
    if (strcmp(tempBuffer, "echo")) {
      strncpy(tempBuffer, buffer, 7);
      if(strcmp(tempBuffer, "echo $?")) {
        printf("%d\n",ret);
      }
      else {
        strncpy(tempBuffer, (buffer+5), INPUT_BUFFER-5);
        printf("%s",tempBuffer);
      }
    }
    else {
      if(strlen(buffer)>255) {
        printf("Path is too long\n");
      }
      else {
        strncpy(tempBuffer,buffer,strlen(buffer)-1);
        ret = exec(tempBuffer);
        if(ret == -1) {
          printf("%s: command not found.\n",tempBuffer);
        }
      }
    }
  }
  return EXIT_FAILURE;
}
