soma = 0.0
qtd = 0
for i in range(6):
	valor = float(input())
	if valor > 0.0:
		qtd += 1
		soma += valor

print("{} valores positivos".format(qtd))
print("{:.1f}".format(soma/qtd))