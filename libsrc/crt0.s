/*
 * crt0.s 
 *	Assembly language startup for C programs
 */

        .text   
        .align  2

/* -------------------------------------------------------------
 * __start
 *	Initialize running a C program, by calling "main". 
 *
 * 	NOTE: This has to be first, so that it gets loaded at
 *	the beginning of the text segment.
 * -------------------------------------------------------------
 */

	.globl __start
	.ent	__start
__start:
	subu	$sp,$sp,16  /* GCC expects spill space for r4-r7 */
	jal	main
	addiu	$2,$0,10
	syscall		    /* If we return from main, exit. */
	.end __start

/* dummy function to keep gcc happy */
        .globl  __main
        .ent    __main
__main:
        j       $31
        .end    __main

