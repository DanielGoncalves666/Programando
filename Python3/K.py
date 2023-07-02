def gerador():
    return [i + 1 for i in range(9)]


def quadrante(mat, i, h):
    if i < 3:
        i = 0
        if h < 3:
            h = 0
        elif h < 6:
            h = 3
        else:
            h = 6
    elif i < 6:
        i = 3
        if h < 3:
            h = 0
        elif h < 6:
            h = 3
        else:
            h = 6
    else:
        i = 6
        if h < 3:
            h = 0
        elif h < 6:
            h = 3
        else:
            h = 6

    vet = []
    for c in range(3):
        for d in range(3):
            if mat[i + c][h + d] != "#":
                vet.append(mat[i + c][h + d])
    return vet


mat = []
for i in range(9):
    linha = input().split(" ")
    mat.append(linha)

possiveis = [[h for h in range(10)] for i in range(5)]

posicoes = []
for i in range(9):
    for h in range(9):
        if mat[i][h] == "#":
            posicoes.append([i, h])

while len(posicoes) > 0:
    for i in range(len(posicoes)):
        [a, b] = posicoes[i]

        # linha
        aux = gerador()
        for x in range(9):
            if mat[a][x] != "#":
                try:
                    aux.remove(int(mat[a][x]))
                except ValueError:
                    continue

        if len(aux) < len(possiveis[i]):
            possiveis[i] = []
            possiveis[i].extend(aux)

        # coluna
        aux = gerador()
        for y in range(9):
            if mat[y][b] != "#":
                try:
                    aux.remove(int(mat[y][b]))
                except ValueError:
                    continue

        if len(aux) < len(possiveis[i]):
            possiveis[i] = []
            possiveis[i].extend(aux)

        # quadrante
        aux = gerador()
        quad = quadrante(mat,a,b)
        for y in quad:
            try:
                aux.remove(int(y))
            except ValueError:
                continue

        if len(aux) < len(possiveis[i]):
            possiveis[i] = []
            possiveis[i].extend(aux)

    for i in range(len(posicoes)):
        if len(possiveis[i]) == 1:
            [a,b] = posicoes[i]
            mat[a][b] = possiveis[i][0]

            possiveis.pop(i)
            posicoes.pop(i)
            break


for i in range(9):
    for h in range(9):
        print(f"{mat[i][h]} ",end="")
    print()
