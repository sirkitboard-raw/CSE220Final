.globl read
read:
  li $v0, 14
  syscall
  jr $ra
