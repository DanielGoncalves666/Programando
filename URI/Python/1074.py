N = int(input())

i = 0
while i < N:
	valor = int(input())
	if valor == 0:
		print("NULL")
	elif valor % 2 == 0:
		print("EVEN", end = " ")
	elif valor % 2 == 1:
		print("ODD", end = " ")

	if valor > 0:
		print("POSITIVE")
	elif valor < 0:
		print("NEGATIVE")
	i += 1