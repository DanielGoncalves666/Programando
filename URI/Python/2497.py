qtd = 0
while(True):
	N = int(input())

	if N == -1:
		break
	
	qtd += 1
	ciclos = N // 2

	print("Experiment {}: {} full cycle(s)".format(qtd,ciclos))
