def dobro(x):
	return 2 * x

valor = [1,2,3,4,5]

valor_dobrado = list(map(dobro,valor))#recebe a operação a ser realizada e a lista
print(valor_dobrado)
#list() converte o que for passao para uma lista

lista = list(map(int,input().split()))
print(lista)