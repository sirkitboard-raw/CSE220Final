#
# "Stub" for interfacing C to the MARS "print character" system call.
# C places the argument in register a0, so all that is necessary is
# to load v0 (register 2) with the system call code (11) and issue
# the system call.
#
.globl putchar
putchar: li	$v0, 11
	 syscall
	 jr	$ra
