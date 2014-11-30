.globl open
open:
  li $v0, 13
  syscall
  jr $ra
