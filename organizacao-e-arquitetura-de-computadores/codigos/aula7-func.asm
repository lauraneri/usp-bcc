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
	jal fat		#retorna em a1 o fatorial
	add s1, zero, a1 #salva em a1 o fatorial
	

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
	
	li a7, 10 #finalizando
	ecall
	
fat:	
	addi a1, zero, 1 #fat = 1
	addi t0, zero, 1 #condição de parada
	
loop_fat:
	ble a0, t0, sai_loop
	mul a1, a1, a0	#fat = fat * count
	addi a0, a0, -1	#count = count - 1
	j loop_fat

sai_loop:
	jr ra
