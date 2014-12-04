#include "setjmp.h"
#include "lib.h"

void longjmp_cse(struct jmp_buf *env, int val) {
  int sp = env->sp;
  int fp = env->fp;
  int ra = env->ra;
  setJumpBuf(val, sp,fp,ra, env->sregs[0], env->sregs[1], env->sregs[2], env->sregs[3], env->sregs[4], env->sregs[5], env->sregs[6], env->sregs[7]);
}

//val, env->sp, env->fp, env->ra, env->sregs[0], env->sregs[1], env->sregs[2], env->sregs[3], env->sregs[4], env->sregs[5], env->sregs[6], env->sregs[7]
