#include "lib.h"
#include "string.h"


int main(void) {
        char buffer[256];
        char* filename="readFile";
        int i;
        int fd;
        int read1;
        fd = open(filename,0,0);
        read1 = read(fd,buffer,256);
        if(read>0) {
          for(i = 0; i < 256; i++) {
            putchar(buffer[i]);
          }
        }
        else {
          for(i=0;i<8;i++) {
            putchar(filename[i]);
          }
        }
        close(fd);
        return 0;
}
