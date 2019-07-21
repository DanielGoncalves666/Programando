L = [] # essa lista esta vazia
R = [1,3,5,7]  #inicializamos a lista com alguns valores
#para criar uma lista(que eu chamaria de vetor), basta fazer como acima
#em uma list pode ter valores de diversos tipos diferentes
H = [1,3.0,"aka",True]

print(type(L))
# a função type() retorna o tipo da variavel

print(R)#imprime os valores da lista
print(H)

#para adicionar variaveis ao final de uma lista ja inicializada usamos o .append
R.append(10.0)
#entre os parenteses inserimos aquilo que sera adicionado
print(R)

#para se acessar elementos especificos de uma lista, basta colocar o nome da lista e entre colchetes o seu index
print(R[0])


#para mudar o valor de uma determinada posição:
R[0] = 100
print(R[0])

#podemos acessar o ultimo elemento da lista pelo indice -1
print(R[-1])
#-2 vai acessar o penultimo


#deletar elementos da lista
del R[0]
print(R)