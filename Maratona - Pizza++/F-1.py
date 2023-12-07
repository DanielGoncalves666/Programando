def remove_intervalos(vet, ini, fim):
    for i in range(fim,ini - 1, -1):
        vet.pop(i)

qtd = 0
while True:
    qtd += 1
    P,S = input().split(" ")
    P = int(P)
    S = int(S)

    if P == 0 and S == 0:
        break

    intervalos = []

    for i in range(S):
        A,B = input().split(" ")
        A = int(A)
        B = int(B)

        if len(intervalos) == 0:
            intervalos.append([A,B])
        else:
            if B < intervalos[0][0]: #intervalo menor
                intervalos.insert(0, [A, B])
                continue

            if A > intervalos[-1][1]: #intervalo maior
                intervalos.append([A,B])
                continue

            index_ini = -1
            index_fim = -1
            for h in range(len(intervalos)):
                ini, fim = intervalos[h]

                if index_ini != -1:
                    if B > fim:
                        if h + 1 == len(intervalos):
                            index_fim = h
                            intervalos[index_ini][0] = A
                            intervalos[index_ini][1] = B

                            remove_intervalos(intervalos, index_ini + 1, index_fim)
                            break
                        elif B < intervalos[h + 1][0]:
                            index_fim = h
                            intervalos[index_ini][0] = A
                            intervalos[index_ini][1] = B

                            remove_intervalos(intervalos,index_ini + 1, index_fim)
                            break
                        else:
                            continue
                    else: # B <= fim
                        B = fim
                        index_fim = h
                        intervalos[index_ini][0] = A
                        intervalos[index_ini][1] = B
                        remove_intervalos(intervalos, index_ini + 1, index_fim)
                        break

                if A <= ini:
                    if B < ini: # novo intervalo
                        intervalos.insert(h, [A,B])
                        break
                    elif B <= fim: # expande à direita
                        intervalos[h][0] = A
                        break
                    elif h + 1 == len(intervalos): # expande à direita e à esquerda
                        intervalos[h][0] = A
                        intervalos[h][1] = B
                        break
                    elif B < intervalos[h + 1][0]: # expande à direita e à esquerda
                        intervalos[h][0] = A
                        intervalos[h][1] = B
                        break
                    else:
                        index_ini = h
                elif A >= ini and A <= fim:
                    if B > fim and h + 1 == len(intervalos):
                        intervalos[h][1] = B
                        break
                    elif B > fim and B < intervalos[h + 1][0]:
                        intervalos[h][1] = B
                        break
                    else:
                        A = ini
                        index_ini = h

    print(f"Teste {qtd}")
    for ini, fim in intervalos:
        print(f"{ini} {fim}")

    print()

