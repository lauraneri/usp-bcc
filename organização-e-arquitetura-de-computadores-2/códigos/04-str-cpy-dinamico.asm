	.data
	.align 0
str_src: .asciz "Oi mae!!"
p:	.word #variavel ponteiro


	.text
	.align 0
	.globl main
	
main:	#calcular tamanho da string

	#t1: contador
	li t1, 0
	
	#s0: endereço
	la s0, str_src
	
	#t0: caracter lido
loop_tam:
	lb t0, 0(s0)
	
	#avançar o endereço na string
	addi s0, s0, 1
	
	#incrementar contador
	addi t1, t1, 1
	
	#verificar condição de continuar no loop
	bne t0, zero, loop_tam
	
	#aloca espaço na heap
	li a7, 9	#strk
	
	#copia o tamanho da string p/ o reg a0
	add a0, zero, t1
	ecall
	
	#armazenar o conteúdo do a0
	#na posição de memória referenciada
	#por p
	
	#t2: endereço do 1o byte apontado por p
	la t2, p
	
	#armazenar a0 na posição apontada por t2
	sw a0, 0(t2)
	
	#preparar p fazer a cópia
	
	#s0: end str_src
	la s0, str_src
	
	#s1: end string destino
	la t2, p
	lw s1, 0(t2)
	
	#cópia
loop_cpy:
	lb t0, 0(s0)
	sb t0, 0(s1)
	addi s0, s0, 1
	addi s1, s1, 1
	bne t0, zero, loop_cpy
	
	#impressao da string copiada
	li a7, 4
	la t2, p
	lw a0, 0(t2)
	ecall
	
	#encerrar
	li, a7, 10
	ecall