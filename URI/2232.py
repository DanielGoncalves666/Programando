import math

N = int(input())

for i in range(N):
    T = int(input())
    soma = 0
    for h in range(0,T):
        soma += math.pow(2,h)

    print("{:.0f}".format(soma))

