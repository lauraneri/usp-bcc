	.data
	.align 0
str1: 	.asciiz "Hello World++!"
str2:	.asciiz "Hello World--!"
	.align 2

	.text
	.globl main

main:
	addi a0, zero, 5
	ecall
	
	add s0, a7, zero
	blt s0, zero, print_neg
	
	addi a0, zero, 4
	la a7, str1
	ecall
	
	j the_end
	
print_neg:
	addi a0, zero, 4
	la a7, str2
	ecall

the_end:
	addi a0, zero, 1
	add a7, zero, s0
	ecall
	
	li a0, 10
	ecall
	
	