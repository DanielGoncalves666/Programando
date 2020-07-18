from math import pow

N = int(input())

for i in range(N):
	T = int(input())

	aux = 1; total = T
	for h in range(1,T+1):
		if h == pow(aux,2):
			aux += 1
			total -= 1

	print(total)