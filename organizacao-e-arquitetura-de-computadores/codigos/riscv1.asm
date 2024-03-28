	.data
	.align 0
str1: 	.asciiz "Hello World++!"
str2:	.asciiz "Hello World--!"
	
	.text
	.align 2
	.globl main

main:
	addi a7, zero, 5
	ecall
	
	add s0, a0, zero
	blt s0, zero, print_neg
	
	addi a7, zero, 4
	la a0, str1
	ecall
	
	j the_end
	
print_neg:
	addi a7, zero, 4
	la a0, str2
	ecall

the_end:
	addi a7, zero, 1
	add a0, zero, s0
	ecall
	
	li a7, 10
	ecall
	
	