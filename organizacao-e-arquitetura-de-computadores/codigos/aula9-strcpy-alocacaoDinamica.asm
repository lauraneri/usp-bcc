	.data
	.align 0
str_src: .asciz "Hello!"
	.align 2
ptr:	.word

	.text
	.align 2
	.globl main

main:
	#calcular o tamanho da str_src
	#t3 armazena o tamanho da string
	addi t3, zero, 0
	
	#coloca em t0 o endereço de 1º byte de str_src
	la t0, str_src
	
loop:
	#lê o conteúdo do byte apontado por t0
	lb t2, 0(t0)
	
	#incrementa o contador t3
	addi t3, t3, 1
	
	#avança o ponteiro da str_src
	addi t0, t0, 1
	
	#se t2 for diferente de zero, volta no loop
	bne t2, zero, loop
	
	#serviço 9 da ecall aloca dinamicamente bytes na heap
	li a7, 9
	add a0, zero, t3
	ecall
	
	#salva o valor retornado na ecall (a0) em ptr
	la t4, ptr
	sw a0, 0(t4)
	
	#str_cpy
	#t0 endereço da string origem
	#t1 endereço da string destino
	
	la t0, str_src
	la t4, ptr
	lw t1, 0(t4)
	
	#finalizando o programa
	li a7, 10
	ecall