area = int(input())
N = int(input())

qtd = 0
for i in range(N):
    estrela = int(input())
    if estrela * area >= 40000000:
        qtd += 1

print(qtd)
