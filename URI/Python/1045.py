lista = input().split()
lista[0] = float(lista[0])
lista[1] = float(lista[1])
lista[2] = float(lista[2])

i = 0
while i < 2:
	if lista[i] < lista[i+1]:
		aux = lista[i]
		lista[i] = lista[i+1]
		lista[i+1] = aux
		i = 0
	else:
		i += 1

def triangulo(a,b,c):
	if a >= b + c:
		print("NAO FORMA TRIANGULO")
	else:
		if a**2 == b**2 + c**2:
			print("TRIANGULO RETANGULO")
		elif a**2 > b**2 + c**2:
			print("TRIANGULO OBTUSANGULO")
		elif a**2 < b**2 + c**2:
			print("TRIANGULO ACUTANGULO")
		
		if a == b and b == c:
			print("TRIANGULO EQUILATERO")
		elif a == b or b == c or c == a:
			print("TRIANGULO ISOSCELES")

triangulo(lista[0],lista[1],lista[2])