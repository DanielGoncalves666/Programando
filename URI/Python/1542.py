from math import trunc

while True:
	try:
		Q, D, P = list(map(int,input().split()))
	except ValueError:
		break

	result = trunc(((Q*D)/(P-Q))*P)

	if result == 1:
		print("1 pagina")
	else:
		print("{:.0f} paginas".format(result))