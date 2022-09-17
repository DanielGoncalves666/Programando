N = int(input())
lista = input().split()


maior = 0 #o numero minimo é 1

for i in lista:
	num = int(i)

	if maior < num:
		maior = num

print(maior+1)