lista = list(map(int,input().split()))

maior = 0
for i in lista:
    if i == 0:
        print(maior)
        break

    if maior < i:
        maior = i
