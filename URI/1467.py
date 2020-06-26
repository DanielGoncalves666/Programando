while True:
	try:
		A, B, C = list(map(int,input().split()))
		soma = A + B + C

		if soma == 0 or soma == 3:
			print("*")
		elif soma == 1:
			if A == 1:
				print("A")
			elif B == 1:
				print("B")
			else:
				print("C")
		elif soma == 2:
			if A == 0:
				print("A")
			elif B == 0:
				print("B")
			else:
				print("C")

	except EOFError:
		break