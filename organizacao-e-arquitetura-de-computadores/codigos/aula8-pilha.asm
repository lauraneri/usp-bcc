	.data

	.text
	.align 2
	.globl main
	
main:
	addi sp, sp, -12 #reserva de 3 words (12 bytes) na pilha 
	
	sw s0, 0(sp) 	#salvando registradores na stack (pilha)
	sw s1, 4(sp)
	sw ra, 8(sp)
	
	lw ra, 8(sp)	#retornando os valores da pilha aos registradores
	lw s1, 4(sp)
	lw s0, 0(sp)
	
	addi, sp, sp, 12 #liberando a pilha
	
	li a7, 10	#finalizando
	ecall