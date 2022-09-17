N = int(input())

i = 0
qtd = 0
while i < N:
	valor = int(input())
	if valor >= 10 and valor <= 20:
		qtd += 1

	i += 1

print("{} in".format(qtd))
print("{} out".format(N-qtd))