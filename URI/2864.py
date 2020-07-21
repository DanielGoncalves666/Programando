from math import pow

N = int(input())

for i in range(N):
	a,b,c = list(map(int,input().split()))

	delta = pow(b,2) - 4 * a * c
	result = -delta / (4.0*a)

	print("{:.2f}".format(result))
