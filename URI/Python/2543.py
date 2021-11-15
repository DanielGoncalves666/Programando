while True:
	try:
		N,I = list(map(int,input().split()))
	except EOFError:
		break

	qtd = 0
	for i in range(N):
		ID, jogo = list(map(int,input().split()))

		if ID == I and jogo == 0:
			qtd += 1

	print(qtd)