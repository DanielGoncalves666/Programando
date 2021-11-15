a = 7
for i in range(1,10,2):
	for j in [a,a-1,a-2]:
		print("I={} J={}".format(i,j))
	a += 2