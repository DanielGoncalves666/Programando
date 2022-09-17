N = int(input())
V = input().split()

#len retorna o tamanho de V

for i in range(len(V)):
    V[i] = int(V[i])

total = 0

for elemento in V:
    total = total + elemento

print(total)


#uma maneira mais facil de somar o elemento de uma lista é usando a função sum(), que recebe como argumento uma lista