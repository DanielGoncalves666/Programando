def area_circunferencia(raio):
	pi = 3.14159
	return pi * (raio ** 2)

raio = float(input())
area = area_circunferencia(raio)
print("A={:.4f}".format(area))