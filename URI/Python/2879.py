N = int(input())

total = 0
for i in range(N):
    carro = int(input())

    if carro == 2 or carro == 3:
        total += 1

print(total)
