.globl getJumpBuf
getJumpBuf:
  addi $sp, $sp, -44
  sw $sp, 0($sp)
  sw $fp, 4($sp)
  sw $ra, 8($sp)
  sw $s0, 12($sp)
  sw $s1, 16($sp)
  sw $s2, 20($sp)
  sw $s3, 24($sp)
  sw $s4, 28($sp)
  sw $s5, 32($sp)
  sw $s6, 36($sp)
  sw $s7, 40($sp)
  addi $sp, $sp, 44
  add $v0, $zero, $sp
  jr $ra
