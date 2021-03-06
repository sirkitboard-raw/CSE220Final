#ifndef LIB_H
#define LIB_H
/*
 * Function prototypes for C library functions.
 * This header file should be included in any C file
 * that needs to use any of these functions.
 */

/* basic i/o syscalls */
void putchar(char c);

void putint(int a);

void puthex(int a);

void putbinary(int a);

void putunisgned(int a);

void putoctal(int a);

int open(char *filename, int flags, int mode);

int close(int fd);

int read(int fd, char* buffer, int num);

int write(int fd, char* buffer, int num);

char* readstring(char* buffer, int size);

int getsp();

inline int* getJumpBuf() __attribute__ ((always_inline));

void setJumpBuf(int val, int sp, int fp, int ra, int a, int b, int c, int d, int e, int f, int g, int h);

int load(int *address);

/* System syscalls */
void exit(void);

#endif
