	.data
	.align 0
str1:	.asciz "Entre com um número: "
str2:	.asciz "O fatorial de "
str3:	.asciz " é "
	.text
	.align 2
	.globl main

main:
	li a7, 4	#addi a7, zero, 4
	la a0, str1
	ecall
	li a7, 5
	ecall		#a0 está o valor digitado
	
	add s0, zero, a0 #move s0, a0
	addi s1, zero, 1 #fat = 1
	add s2, zero, s0 #count = n
	addi t0, zero, 1 #condição de parada
	
loopfat:
	ble s2, t0, sai_loop
	mul s1, s1, s2	#fat = fat * count
	addi s2, s2, -1	#count = count - 1
	j loopfat
	
sai_loop:
	li a7, 4
	la a0, str2
	ecall
	
	li a7, 1
	add a0, zero, s0
	ecall
	
	li a7, 4
	la a0, str3
	ecall
	
	li a7, 1
	add a0, zero, s1
	ecall
	
	li a7, 10
	ecall