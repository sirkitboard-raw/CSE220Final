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
L4000020:	addiu $29,$29,-280
	sw $31,276($29)
	sw $30,272($29)
	jal L4000010
	addu $30,$29,$0
	addiu $4,$0,256
	jal L4000070
	addiu $5,$30,16
	jal L40000b0
	addiu $4,$30,16
	jal L4000220
	addu $4,$2,$0
	addu $2,$0,$0
	addu $29,$30,$0
	lw $31,276($29)
	lw $30,272($29)
	jr $31
	addiu $29,$29,280
	sll $0,$0,0
	sll $0,$0,0
L4000070:	addiu $29,$29,-24
	sw $31,20($29)
	sw $30,16($29)
	addu $30,$29,$0
	sw $4,24($30)
	sw $5,28($30)
	lw $4,28($30)
	lw $5,24($30)
	jal L4000230
	sll $0,$0,0
	addu $29,$30,$0
	lw $31,20($29)
	lw $30,16($29)
	jr $31
	addiu $29,$29,24
	sll $0,$0,0
L40000b0:	addiu $29,$29,-16
	sw $30,8($29)
	addu $30,$29,$0
	sw $4,16($30)
	sw $0,0($30)
	sw $0,4($30)
L40000c8:	lw $3,16($30)
	lw $2,4($30)
	sll $0,$0,0
	addu $2,$3,$2
	lb $2,0($2)
	sll $0,$0,0
	bne $2,$0,L40000f0
	sll $0,$0,0
	j L4000114
	sll $0,$0,0
L40000f0:	lw $2,0($30)
	sll $0,$0,0
	addiu $2,$2,1
	sw $2,0($30)
	lw $2,4($30)
	sll $0,$0,0
	addiu $2,$2,1
	j L40000c8
	sw $2,4($30)
L4000114:	lw $2,0($30)
	addu $29,$30,$0
	lw $30,8($29)
	jr $31
	addiu $29,$29,16
	addiu $29,$29,-48
	sw $31,40($29)
	sw $30,36($29)
	sw $16,32($29)
	addu $30,$29,$0
	sw $4,48($30)
	sw $5,52($30)
	addiu $2,$0,1
	sw $2,20($30)
	lw $4,48($30)
	jal L40000b0
	sll $0,$0,0
	addu $16,$2,$0
	lw $4,52($30)
	jal L40000b0
	sll $0,$0,0
	beq $16,$2,L4000178
	sll $0,$0,0
	j L4000200
	sw $0,24($30)
L4000178:	sw $0,16($30)
L400017c:	lw $4,48($30)
	jal L40000b0
	sll $0,$0,0
	lw $3,16($30)
	sll $0,$0,0
	sltu $2,$3,$2
	bne $2,$0,L40001a4
	sll $0,$0,0
	j L40001f4
	sll $0,$0,0
L40001a4:	lw $3,48($30)
	lw $2,16($30)
	sll $0,$0,0
	addu $4,$3,$2
	lw $3,52($30)
	lw $2,16($30)
	sll $0,$0,0
	addu $2,$3,$2
	lb $3,0($4)
	lb $2,0($2)
	sll $0,$0,0
	beq $3,$2,L40001e0
	sll $0,$0,0
	j L40001f4
	sw $0,20($30)
L40001e0:	lw $2,16($30)
	sll $0,$0,0
	addiu $2,$2,1
	j L400017c
	sw $2,16($30)
L40001f4:	lw $2,20($30)
	sll $0,$0,0
	sw $2,24($30)
L4000200:	lw $2,24($30)
	addu $29,$30,$0
	lw $31,40($29)
	lw $30,36($29)
	lw $16,32($29)
	jr $31
	addiu $29,$29,48
	sll $0,$0,0
L4000220:	addiu $2,$0,1
	syscall
	jr $31
	sll $0,$0,0
L4000230:	addiu $2,$0,8
	syscall
	jr $31
	sll $0,$0,0
data:	.data
bss:	.data
	.space	0
