lista = input().split()
a = int(lista[0])
b = int(lista[1])
c = int(lista[2])
d = int(lista[3])

if b > c and d > a and c+d > a+b and c > 0 and d > 0 and a%2 == 0:
	print("Valores aceitos")
else:
	print("Valores nao aceitos")