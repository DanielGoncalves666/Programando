lista = input().split()
lista[0] = int(lista[0])
lista[1] = int(lista[1])
lista[2] = int(lista[2])

lista2 = []
for i in range(3):
	lista2.append(lista[i])

x = 0
while(x<2):
	if(lista2[x] > lista2[x+1]):
		aux = lista2[x]
		lista2[x] = lista2[x+1]
		lista2[x+1] = aux
		x = 0
	else:
		x += 1

for i in range(3):
	print("{}".format(lista2[i]))

print()

for i in range(3):
	print("{}".format(lista[i]))