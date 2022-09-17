string = " "

while(True):
	N = int(input())

	if N == 0:
		break

	string = string.replace(string,input())

	direcao = 0
	for i in string:
		if i == 'E':
			direcao -= 1
		elif i == 'D':
			direcao += 1

		if direcao == -1:
			direcao = 3
		elif direcao == 4:
			direcao = 0

	if direcao == 0:
		print("N")
	elif direcao == 1:
		print("L")
	elif direcao == 2:
		print("S")
	elif direcao == 3:
		print("O")