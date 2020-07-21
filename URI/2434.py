N, saldo = list(map(int,input().split()))

menor = saldo
for i in range(N):
	num = int(input())
	saldo += num

	if saldo < menor:
		menor = saldo

print(menor)