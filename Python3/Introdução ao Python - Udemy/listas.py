minha_lista = ["abacaxi","melancia","abacate"]

print(minha_lista)

for item in minha_lista:
	print(item)

tamanho = len(minha_lista)# serve tanto para strings como para listas
print(tamanho)

minha_lista.append("limao")#adiciona ao final da lista

if "abacaxi" in minha_lista:#verifica se o elemento está na lista
	print("Abacaxi esta na lista")

print(minha_lista)
del minha_lista[3]
print(minha_lista)

lista = sorted(minha_lista)#retorna a lista ordenada

minha_lista.sort()# realiza a ordenação da lista
print(minha_lista)
minha_lista.sort(reverse = True)#realiza a ordenação de maneira decrescente
print(minha_lista)

minha_lista.reverse()#inverte os elementos da lista