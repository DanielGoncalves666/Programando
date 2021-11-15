N = int(input())

Carlos = 0
for i in range(N):
	num = int(input())
	
	if Carlos == -1:
		continue

	if i == 0:
		Carlos = num
	elif Carlos < num:
		print("N")
		Carlos = -1

if Carlos != -1:
	print("S")