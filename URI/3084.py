while True:
	try:
		hora, minuto = list(map(int,input().split()))
	except EOFError:
		break

	h = hora // 30
	m = (minuto // 30) * 5 + ((minuto % 30) // 6)

	if h > 9:
		print("{}:".format(h), end = "")
	else:
		print("0{}:".format(h), end = "")

	if m > 9:
		print("{}".format(m))
	else:
		print("0{}".format(m))