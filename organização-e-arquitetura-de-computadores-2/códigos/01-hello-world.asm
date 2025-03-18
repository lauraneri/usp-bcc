	.data	#dados do código
hello:	.asciz	"Hello World"	#string a ser impressa
	
	.text	#programa
	.globl main
main:
	#imprimir a string hello
	#a7: serviço 4 da ecall
	#a0: endereço do 1o byte da string a ser impressa
	
	#carregar o valor 4 no registrador a7 (print string)
	li a7, 4
	
	#carregar o endereço do 1o byte no registrador 
	la a0, hello
	
	#chamada a ecall
	ecall
	
	#finalizar o programa
	#a7: serviço 10 da ecall (finalizar o programa)
	li a7, 10
	
	#chamada a ecall
	ecall