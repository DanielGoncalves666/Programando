v = 0

while v < 5:
    print(v)
    v = v + 1

print()

#temos a variavel i e apos o in uma lista
for i in [1,2,3]:
    print(i)

print()

#para facilitar podemos usar o comando range()
for i in range(1,4):            #se colocassemos range(1,100,2), o terceiro valor equivaleria a i+=2
    print(i)
#ira imprimir de 1 ate 4, pois o segundo valor n esta incluido no intervalo
#quando o range começa em 0, podemos omiti-lo, range(10)


#o range n é uma lista, ele indica um intervalo

R = range(10)
print(R)
#isso retornara range(0,10)
#para transformarmos R em uma lista usamos list(R)
print(list(R))