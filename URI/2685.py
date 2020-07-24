while True:
	try:
		N = int(input())
	except EOFError:
		break

	if N == 360 or N == 0 or (N > 0 and N < 90):
		print("Bom Dia!!")
	elif N >= 90 and N < 180:
		print("Boa Tarde!!")
	elif N >= 180 and N < 270:
		print("Boa Noite!!")
	else:
		print("De Madrugada!!")