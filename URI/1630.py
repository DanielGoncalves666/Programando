while True:
	try:
		N,M = list(map(int,input().split()))
	except EOFError:
		break

	MDC = 0
	if N == M:
		MDC = N
	else:
		R0 = 0; R1 = 0; R2 = 0
		
		if N > M:
			R0 = N
			R1 = M
		else:
			R0 = M
			R1 = N

		while True:
		
			R2 = R0 % R1

			if R2 == 0:
				MDC = R1
				break

			R0 = R1
			R1 = R2

	total = (N / MDC) * 2 + (M / MDC) * 2
	print("{:.0f}".format(total))