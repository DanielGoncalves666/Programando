total = 0
for i in range(2):
	lista = input().split()
	total += int(lista[1])*float(lista[2])

print("VALOR A PAGAR: R$ {:.2f}".format(total))