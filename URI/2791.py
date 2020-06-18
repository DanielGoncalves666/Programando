lista = list(map(int,input().split()))

qtd = 1
for i in lista:
	if i == 1:
		print(qtd)
	else:
		qtd += 1
