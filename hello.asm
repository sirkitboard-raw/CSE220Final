# Created by Coff2Asm
# NOTE: Must be executed with delayed branching enabled in MARS
text:	.text
	jal L4000020
	addiu $29,$29,-16
	addiu $2,$0,10
	syscall
L4000010:	jr $31
	sll $0,$0,0
	sll $0,$0,0
	sll $0,$0,0
L4000020:	addiu $29,$29,-32
	sw $31,28($29)
	sw $30,24($29)
	jal L4000010
	addu $30,$29,$0
	lui $4,0x1001
	jal L4000060
	addiu $4,$4,0
	sw $2,16($30)
	lw $2,16($30)
	addu $29,$30,$0
	lw $31,28($29)
	lw $30,24($29)
	jr $31
	addiu $29,$29,32
	sll $0,$0,0
L4000060:	addiu $29,$29,-2080
	sw $31,2076($29)
	sw $30,2072($29)
	addu $30,$29,$0
	sw $4,2080($30)
	lw $4,2080($30)
	addu $5,$0,$0
	jal L40000d0
	addu $6,$0,$0
	sw $2,2068($30)
	lw $2,2068($30)
	sll $0,$0,0
	bltz $2,L40000b4
	sll $0,$0,0
	lw $4,2068($30)
	addiu $5,$30,16
	jal L40000e0
	addiu $6,$0,2048
	jal L40000f0
	addiu $4,$30,16
	sw $2,2064($30)
L40000b4:	lw $2,2064($30)
	addu $29,$30,$0
	lw $31,2076($29)
	lw $30,2072($29)
	jr $31
	addiu $29,$29,2080
	sll $0,$0,0
L40000d0:	addiu $2,$0,13
	syscall
	jr $31
	sll $0,$0,0
L40000e0:	addiu $2,$0,14
	syscall
	jr $31
	sll $0,$0,0
L40000f0:	jalr $31,$4
	sll $0,$0,0
	jr $31
	sll $0,$0,0
data:	.data
	.byte	0x2f, 0x75, 0x73, 0x72
	.byte	0x2f, 0x6c, 0x6f, 0x63
	.byte	0x61, 0x6c, 0x2f, 0x62
	.byte	0x69, 0x6e, 0x2f, 0x73
	.byte	0x68, 0x65, 0x6c, 0x6c
	.byte	0x62, 0x69, 0x6e, 0x2f
	.byte	0x72, 0x61, 0x6e, 0x64
	.byte	0x0, 0x0, 0x0, 0x0
bss:	.data
	.space	0
