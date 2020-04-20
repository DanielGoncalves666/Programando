from math import fabs

lista = input().split()

for i in range(3):
	lista[i] = float(lista[i])

def area_trapezio(a,b,c):
	print("Area = {:.1f}".format(((a+b)*c)/2))

def verifica_triangulo(a,b,c):
	if(a < b + c and b < a + c and c < b + a):
		if(a > fabs(b - c) and b > fabs(a - c) and c > fabs(a - b)):
			print("Perimetro = {:.1f}".format(a + b + c))
		else:
			area_trapezio(a,b,c)
	else:
		area_trapezio(a,b,c)

verifica_triangulo(lista[0],lista[1],lista[2])