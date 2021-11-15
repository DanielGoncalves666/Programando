N = int(input())

for i in range(N):
	lista = list(map(float,input().split()))
	media = (lista[0]*2 + lista[1]*3 + lista[2]*5)/10
	print("{:.1f}".format(media))