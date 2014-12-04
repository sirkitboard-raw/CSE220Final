.globl setJumpBuf
setJumpBuf:
  lw $s0, 16($sp)
  lw $s1, 20($sp)
  lw $s2, 24($sp)
  lw $s3, 28($sp)
  lw $s4, 32($sp)
  lw $s5, 36($sp)
  lw $s6, 40($sp)
  lw $s7, 44($sp)
  add $ra, $zero, $a3
  add $fp, $zero, $a2
  add $sp, $zero, $a1
  add $v0, $zero, $a0
  jr $ra
