.globl write
write:
  li $v0, 15
  syscall
  jr $ra
