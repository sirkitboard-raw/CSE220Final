#include "setjmp.h"
#include "stdio.h"
#include "unistd.h"
#include "lib.h"
void foo();
void bar();

struct jmp_buf env;

int main(int argc, char *argv) {
  // char *temp = "Hello!";
  // int fd = open("temp.txt",1,0);
  // write(fd, temp, 6);
  // close(fd);
  printf("%o\n",-10);
  int i = fprintf(1,"%d %u %x %o %5s %-5s,\n", -10,-10,-10,-10, "Hi", "Hi");
  putint(i);
  // setjmp_cse(&env);
  // int a = env.sp;
  // putint(a);
  // return 0;
}

// int main(int argc, char *argv[]) {
//   int val;
//   if((val = setjmp_cse(&env)) == 0) {
//     /* "Try block" */
//     printf("In the 'try' block\n");
//     foo();
//   } else {
//     /* "Catch" block */
//     printf("In the 'catch' block, val=%d\n", val);
//   }
//   printf("Program terminating\n");
//   return 0;
// }
//
// void foo() {
//   printf("In function foo\n");
//   bar();
//   printf("Oops, after call to bar (shouldn't happen)\n");
// }
// void bar() {
//   printf("In function bar\n");
//   longjmp_cse(&env,42);
//   printf("Oops, after longjmp (shouldn't happen)\n");
// }
