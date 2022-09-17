from math import floor

N = int(input())

for i in range(N):
	x,y = list(map(float,input().split()))

	print("{:.0f} cm2".format(floor((x*y)/2.0)))