#
# "Stub" for interfacing C to the MARS "exit" system call.
#
.globl exit
exit:	li	$v0, 10
	syscall
	jr	$ra
