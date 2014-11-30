#include "lib.h"
#include "string.h"

int main(void) {
        char buffer[256];
        fgets(256,buffer);
        putint(strlen(buffer));
        return 0;
}
