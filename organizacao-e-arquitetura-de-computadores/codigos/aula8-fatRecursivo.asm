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
	
	add s0, zero, a0 #em s0 vai estar o valor de n
	
	jal fatorial
	
	li a7, 4	#fazendo a impressao das strings, n e resultado --
	la a0, str2
	ecall
	
	li a7, 1
	add a0, zero, s0
	ecall
	
	li a7, 4
	la a0, str3
	ecall
	
	li a7, 1
	add a0, zero, a1
	ecall		#--
	
	li a7, 10 	#finalizando
	ecall
	
			#função recursiva
			#a0 = nro a ser calculado (n)
			#a1 = o fatorial calculado
fatorial:
			#empilhar o ra e a0--
	addi sp, sp, -8
	sw ra, 0(sp)	
	sw a0, 4(sp)	#--
	
	beq a0, zero, retorna_1 #compara o n com 0
	
	#n é diferente de 0
	#atualizar o valor de n
	addi, a0, a0, -1
	
	jal fatorial
	
	lw a0, 4(sp)
	mul a1, a1, a0
	j sai_fat
	
retorna_1:		#condição de parada
	addi a1, zero, 1
	
sai_fat:
	lw ra, 0(sp)
	addi sp, sp, 8
	jr ra