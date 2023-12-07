def gerar(convertido, numeros, possiveis):
    for i in range(8):
        possiveis[i][0] = numeros[convertido[0] * 2]
        possiveis[i + 8][0] = numeros[convertido[0] * 2 + 1]

    for i in range(4):
        possiveis[i][1] = numeros[convertido[1] * 2]
        possiveis[i + 4][1] = numeros[convertido[1] * 2 + 1]
        possiveis[i + 8][1] = numeros[convertido[1] * 2]
        possiveis[i + 12][1] = numeros[convertido[1] * 2 + 1]

    for i in range(2):
        possiveis[i][2] = numeros[convertido[2] * 2]
        possiveis[i + 2][2] = numeros[convertido[2] * 2 + 1]
        possiveis[i + 4][2] = numeros[convertido[2] * 2]
        possiveis[i + 6][2] = numeros[convertido[2] * 2 + 1]
        possiveis[i + 8][2] = numeros[convertido[2] * 2]
        possiveis[i + 10][2] = numeros[convertido[2] * 2 + 1]
        possiveis[i + 12][2] = numeros[convertido[2] * 2]
        possiveis[i + 14][2] = numeros[convertido[2] * 2 + 1]

    possiveis[0][3] = numeros[convertido[3] * 2]
    possiveis[1][3] = numeros[convertido[3] * 2 + 1]
    possiveis[2][3] = numeros[convertido[3] * 2]
    possiveis[3][3] = numeros[convertido[3] * 2 + 1]
    possiveis[4][3] = numeros[convertido[3] * 2]
    possiveis[5][3] = numeros[convertido[3] * 2 + 1]
    possiveis[6][3] = numeros[convertido[3] * 2]
    possiveis[7][3] = numeros[convertido[3] * 2 + 1]
    possiveis[8][3] = numeros[convertido[3] * 2]
    possiveis[9][3] = numeros[convertido[3] * 2 + 1]
    possiveis[10][3] = numeros[convertido[3] * 2]
    possiveis[11][3] = numeros[convertido[3] * 2 + 1]
    possiveis[12][3] = numeros[convertido[3] * 2]
    possiveis[13][3] = numeros[convertido[3] * 2 + 1]
    possiveis[14][3] = numeros[convertido[3] * 2]
    possiveis[15][3] = numeros[convertido[3] * 2 + 1]



N = int(input())
iter = 0
possiveis = [[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0]]
atual = [[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0]]
for _ in range(N):
    vet = input().split(" ")

    senha = vet[-1]
    convertida = []
    for i in senha:
        if i == 'V':
            convertida.append(0)

        if i == 'W':
            convertida.append(1)

        if i == 'X':
            convertida.append(2)

        if i == 'Y':
            convertida.append(3)

        if i == 'Z':
            convertida.append(4)

    numeros = []
    for i in range(len(vet) - 1):
        numeros.append(int(vet[i]))

    if iter == 0:
        iter = 1

        gerar(convertida, numeros, possiveis)
    else:
        gerar(convertida, numeros, atual)

        temp = []
        for i in possiveis:
            if i in atual:
                temp.append(i)

        possiveis = temp


if len(possiveis) == 0:
    print("impossivel")
else:
    strings = []
    for i in possiveis:
        strings.append(f"{i[0]}{i[1]}{i[2]}{i[3]}")

    strings.sort()

    for i in strings:
        print(i)