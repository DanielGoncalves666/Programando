import math

while True:
	try:
		ano = int(input())
		if ano % 100 == 0:
			print(int(ano/100))
		else:
			print(int(math.floor(ano/100)+1))
	except EOFError:
		break
