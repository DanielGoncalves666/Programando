def back(dic, atual, resul, maisVelho, ini):

    if atual == maisVelho and ini != True:
        chaves =


    ini = False
    opcoes = dic[atual]



    for i in opcoes:
        if i not in resul:
            resul[i] = [atual]
            opcoes.remove(i)
            dic[atual] = opcoes
            retorno = back(dic,i,resul,maisVelho, 0)
        else:
            if atual in resul[i]:
                opcoes.remove(i)
                dic[atual] = opcoes
                continue

            if i in resul[atual]:
                opcoes.remove(i)
                dic[atual] = opcoes
                continue

            resul[i] = resul[i] + [atual]
            opcoes.remove(i)
            dic[atual] = opcoes
            retorno = back(dic,i,resul,maisVelho, 0)



while True:
    P,R = input().split(" ")
    P = int(P)
    R = int(R)

    dic = {}
    relacoes = {}
    primeiro = ""
    for i in range(R):

        um, dois = input().split(" ")

        if um not in relacoes:
            relacoes[um] = [dois]
        else:
            relacoes[um] = relacoes[um] + [dois]

        if dois not in dic:
            dic[dois] = 1
            dic[um] = 0
        else:
            dic[dois] += 1

    valores = dic.values()
    if 0 in valores:
        print("Nao")
        break

    valores = relacoes.values()
    for i in valores:
        if len(i) > 1:
            print("Nao")
            break

