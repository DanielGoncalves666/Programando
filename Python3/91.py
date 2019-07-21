N = int(input())
S1 = input()
S2 = input()

qtd = 0
for i in range(N):
    if S1[i] == S2[i]:
        qtd = qtd + 1

print(qtd)