	.data
	.align 0
str1:	.asciz "Hello World++!\n"
str2:	.asciz "Hello World--!\n"
	
	.text
	.align 2
	.globl main
	
main:
	addi a7, zero, 5	#serviço pra ler um inteiro
	ecall
	
	add s0, a0, zero
	blt s0, zero, print_neg
	
	#imprimir str1
	addi a7, zero, 4
	la a0, str1
	ecall
	j the_end

print_neg:
	#imprimir str2
	addi a7, zero, 4
	la a0, str2
	ecall

the_end:
	#imprimir o numero
	addi a7, zero, 1
	add a0, zero, s0
	ecall
	
	#finalizar o programa
	#a7: serviço 10 da ecall (finalizar o programa)
	addi a7, zero, 10
	
	#chamada a ecall
	ecall