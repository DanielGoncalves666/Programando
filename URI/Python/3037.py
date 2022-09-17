N = int(input())

for i in range(N):
    maria = 0
    joao = 0
    for i in range(3):
        ponto, dist = list(map(int,input().split()))
        joao += ponto*dist
    for i in range(3):
        ponto, dist = list(map(int,input().split()))
        maria += ponto*dist
    if maria > joao:
        print("MARIA")
    else:
        print("JOAO")
