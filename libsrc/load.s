.globl load
load:
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jalr $a0
  lw $ra, 0($sp)
	addi $sp, $sp, 4
  jr $ra
