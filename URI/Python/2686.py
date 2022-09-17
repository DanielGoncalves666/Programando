while True:
	try:
		N = float(input())
	except EOFError:
		break

	if N == 360.0 or N == 0.0 or (N > 0.0 and N < 90.0):
		print("Bom Dia!!")
	elif N >= 90.0 and N < 180.0:
		print("Boa Tarde!!")
	elif N >= 180.0 and N < 270.0:
		print("Boa Noite!!")
	else:
		print("De Madrugada!!")

	horas = int(N // 15.0)
	N -= horas*15.0
	horas += 6

	if horas >= 24:
		horas -= 24

	minutos = int(N // 0.25)
	N -= minutos*0.25

	segundos = int(N // 0.04166666)
	
	print("{:02d}:{:02d}:{:02d}".format(horas,minutos,segundos))