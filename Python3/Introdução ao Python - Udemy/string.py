# -*- coding: utf-8 -*-
"""
var1 = 1 --> inteiro
var1 = "1" --> string
var1 = '1' --> string
"""

a = 'Ola'
b = 'Mundo'
c = "!"

concatenar = a + " " + b + c
print(concatenar)

#ao somar strings, simplesmente as juntamos

tamanho = len(concatenar) #retorna o tamanho da string
print(tamanho)

print(concatenar[2])

print(concatenar[0:3])#imprime uma parte da string, posição 0, 1 e 2

