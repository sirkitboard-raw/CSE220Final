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
L4000020:	addiu $29,$29,-296
	sw $31,292($29)
	sw $30,288($29)
	jal L4000010
	addu $30,$29,$0
	lui $2,0x1001
	addiu $2,$2,0
	sw $2,272($30)
	lw $4,272($30)
	addu $5,$0,$0
	jal L4000140
	addu $6,$0,$0
	sw $2,280($30)
	lw $4,280($30)
	addiu $5,$30,16
	jal L4000150
	addiu $6,$0,256
	sw $2,284($30)
	lui $2,0x400
	addiu $2,$2,336
	beq $2,$0,L40000c8
	sll $0,$0,0
	sw $0,276($30)
L400007c:	lw $2,276($30)
	sll $0,$0,0
	slti $2,$2,256
	bne $2,$0,L4000098
	sll $0,$0,0
	j L400011c
	sll $0,$0,0
L4000098:	lw $3,276($30)
	addiu $2,$30,16
	addu $2,$2,$3
	lb $2,0($2)
	sll $0,$0,0
	jal L4000160
	addu $4,$2,$0
	lw $2,276($30)
	sll $0,$0,0
	addiu $2,$2,1
	j L400007c
	sw $2,276($30)
L40000c8:	sw $0,276($30)
L40000cc:	lw $2,276($30)
	sll $0,$0,0
	slti $2,$2,8
	bne $2,$0,L40000e8
	sll $0,$0,0
	j L400011c
	sll $0,$0,0
L40000e8:	lw $3,272($30)
	lw $2,276($30)
	sll $0,$0,0
	addu $2,$3,$2
	lb $2,0($2)
	sll $0,$0,0
	jal L4000160
	addu $4,$2,$0
	lw $2,276($30)
	sll $0,$0,0
	addiu $2,$2,1
	j L40000cc
	sw $2,276($30)
L400011c:	lw $4,280($30)
	jal L4000170
	sll $0,$0,0
	addu $2,$0,$0
	addu $29,$30,$0
	lw $31,292($29)
	lw $30,288($29)
	jr $31
	addiu $29,$29,296
L4000140:	addiu $2,$0,13
	syscall
	jr $31
	sll $0,$0,0
L4000150:	addiu $2,$0,14
	syscall
	jr $31
	sll $0,$0,0
L4000160:	addiu $2,$0,11
	syscall
	jr $31
	sll $0,$0,0
L4000170:	addiu $2,$0,16
	syscall
	jr $31
	sll $0,$0,0
data:	.data
	.byte	0x72, 0x65, 0x61, 0x64
	.byte	0x46, 0x69, 0x6c, 0x65
	.byte	0x0, 0x0, 0x0, 0x0
	.byte	0x0, 0x0, 0x0, 0x0
bss:	.data
	.space	0
