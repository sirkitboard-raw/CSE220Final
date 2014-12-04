#ifndef SETJUMP_J
  #define SETJUMP_J
  struct jmp_buf {
    int ra;
    int sp;
    int fp;
    int sregs[7];
  };
  int setjmp_cse(struct jmp_buf *env);
  void longjmp_cse(struct jmp_buf *env, int val);
#endif
