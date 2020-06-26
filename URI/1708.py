A,B = list(map(int,input().split()))

diff = B - A

if B % diff == 0:
	print(B//diff)
else:
	result = (B - (B % diff))//diff 
	print(result + 1)