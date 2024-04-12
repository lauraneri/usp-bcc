	.data
	.align 0
str_src: .asciz "Hello!"
str_dst: .space 7 #alocando 7 bytes na area estatica de dados com o label str_dist

	
	.text
	.align 2
	.globl main
	
main:
	#carrega em t0 e t1 os endereços
	#do 1° byte das strings str_src e str_dst
	la t0, str_src
	la t1, str_dst
	
	#lê o 1º byte da str_src e armaneza em t2
	lb t2, 0(t0)
	#escreve t2 no 1º byte da str_dst
	sb t2, 0(t1)
	
loop:
	beq t2, zero, sai_loop
	#avança os ponteiros das strings
	addi t0, t0, 1
	addi t1, t1, 1
	
	#lê o byte apontado por t0
	lb t2, 0(t0)
	
	#escreve t2 no byte apontado por t1
	sb t2, 0(t1)
	
	#volta no loop
	j loop

sai_loop:
	#imprime a string copiada
	li a7, 4
	la a0, str_dst
	ecall
	
	li a7, 10
	ecall
