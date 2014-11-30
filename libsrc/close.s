.globl close
close:
  li $v0, 16
  syscall
  jr $ra
