while True:
	N = int(input())

	if N == 0:
		break

	total = 1
	for i in range(2,N+1,1):
		total += pow(i,2)

	print(total)
