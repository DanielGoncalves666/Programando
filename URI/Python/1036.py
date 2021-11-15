import math
lista = input().split()
a = float(lista[0])
b = float(lista[1])
c = float(lista[2])

delta = (b**2) - 4*a*c 

if a == 0.0 or delta < 0.0:
	print("Impossivel calcular")
else:
	r1 = (-b + math.sqrt(delta))/(2*a)
	r2 = (-b - math.sqrt(delta))/(2*a)
	print("R1 = {:.5f}".format(r1))
	print("R2 = {:.5f}".format(r2))

