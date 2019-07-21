N = int(input())
P = []

for i in range(N):
    P.append(int(input()))

dias = 0
soma = 0
resposta = 0
for h in range(N):
    soma = soma + P[h]
    dias = dias + 1
    if soma >= 1000000:
        resposta = dias
        break

print(resposta)