A = input()
B = input()

#input() é a função que recebe valores que o usario entrar
#neste caso, o que o usario digitar sera armazenado em A
#porem, o comando imput armazena dados em forma de string, ou seja, se tentarmos somar A=5 e B=6, vamos obter 56
#pois as duas cadeias de caracteres sao simplesmente juntadas

#desse modo, precisamos transformar ambas as variaveis no tipo que queremos, nese caso inteiro

A = int(A)
B = int(B)
#se somarmos ambas agora, vamos obter 11

#uma maneira de realizarmos a entrada de dois ou mais numeros na msm linha é fazendo o seguinte
C, D = input().split()
#com a função split(), é possivel entrar com mais de um valor na mesma linha de entrada
#o split() separa as entradas

C = int(C)
D = int(D)
#transformamos ambas as variaveis em inteiros

print(A+B)
print(C+D)
