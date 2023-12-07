qtd = 0
while True:
    qtd += 1
    P,S = input().split(" ")
    P = int(P)
    S = int(S)

    if P == 0 and S == 0:
        break

    Praia = [0] * (P + 1)
    Meio = [0] * P

    for i in range(S):
        A,B = input().split(" ")
        A = int(A)
        B = int(B)

        for h in range(A,B + 1):
            Praia[h] += 1

            if h > A:
                Meio[h - 1] += 1

    print(f"Teste {qtd}")
    inter = False
    ini = 0
    fim = 0
    for i in range(len(Praia)):
        if not inter:
            if Praia[i] > 0:
                ini = i
                inter = True
        else:
            if Praia[i] == 0:
                fim = i - 1
                inter = False
                print(f"{ini} {fim}")

            if Praia[i] == 1 and Meio[i - 1] == 0:
                fim = i - 1
                print(f"{ini} {fim}")
                ini = i

    if inter:
        print(f"{ini}  {P}")

    print()

