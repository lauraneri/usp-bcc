""" Teste para compreensão de gerador congruencial linear (LCG em inglês)"""
#mod = a2 100, a = a3 21, c = a4 17, seed = a5 ecall
def lcg(modulo, a, c, semente=None):
    if semente != None:
        lcg.anterior = semente
    num_aleatorio = (lcg.anterior * a + c) % modulo
    lcg.anterior = num_aleatorio
    return num_aleatorio
lcg.anterior = 2222

lista = []
existe = False
for i in range (102):
    num = lcg(100, 21, 17)
    if num in lista:
        existe = True
        print("ACHOU")
    lista.append(num)
    print(num)

if existe == False:
    print("NAO ACHOU")
    
