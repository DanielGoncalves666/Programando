N = int(input())
C = 0
R = 0
S = 0

for i in range(N):
	lista = input().split()
	if lista[1] == 'C':
		C += int(lista[0])
	elif lista[1] == 'R':
		R += int(lista[0])
	else:
		S += int(lista[0])

total = C + R + S

print("Total: {} cobaias".format(total))
print("Total de coelhos: {}".format(C))
print("Total de ratos: {}".format(R))
print("Total de sapos: {}".format(S))
print("Percentual de coelhos: {:.2f} %".format((C/total)*100))
print("Percentual de ratos: {:.2f} %".format((R/total)*100))
print("Percentual de sapos: {:.2f} %".format((S/total)*100))