	.data
	.align 0
str1:	.asciz "Digite um numero de 0 a 12: "
str2:	.asciz "O fatorial de "
str3:	.asciz " eh "
	#Fatorial
	.text
	#Começando a parte de código
	.align 2
	.globl main
	
main:
	#Exibir mensagem para o usuário
	addi a7, zero, 4
	la a0, str1
	ecall
	
	#Lê o número do teclado
	li a7, 5	# 5 - Lê um inteiro, salva em a0
	ecall
	
	#Salvar valor do a0 no s0
	add s0, zero, a0
	
	addi s1, zero, 1 #Salvar resultado no s1
	add t0, zero, s0 #t0 é contador
	
loop:
	#Parar quando o contador for zero
	beq t0, zero, fim
	
	mul s1, s1, t0 #Multiplica valor atualizando a variável
	addi t0, t0, -1
	j loop
	
fim:
	#Exibir mensagem para o usuario
	addi a7, zero, 4
	la a0, str2
	ecall
	
	#Exibir o numero digitado pelo usuario
	addi a7, zero, 1
	add a0, zero, s0
	ecall
	
	#Exibir mensagem para o usuario
	addi a7, zero, 4
	la a0, str3
	ecall	
	
	#Exibir fatorial
	addi a7, zero, 1 # 1 - Imprimir inteiros
	add a0, zero, s1
	ecall
	
	addi a7, zero, 10 # 10 - Fim do programa
	ecall #cabou
	