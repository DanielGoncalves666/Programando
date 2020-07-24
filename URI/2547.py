while(True):
	try:
		N, min, max = list(map(int,input().split()))
	except EOFError:
		break

	qtd = 0
	for i in range(N):
		num = int(input())

		if num <= max and num >= min:
			qtd += 1

	print(qtd)