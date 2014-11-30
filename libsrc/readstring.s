.globl readstring
readstring: li	$v0, 8
   syscall
   jr	$ra
