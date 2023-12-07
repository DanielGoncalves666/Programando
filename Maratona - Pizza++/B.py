while True:
    N = int(input())

    if N == 0:
        break

    for i in range(N):
        vet = input().split(" ")

        for h in range(5):
            vet[h] = int(vet[h])

        Op = "*"

        for h in range(5):
            if vet[h] <= 127:
                if Op != "*":
                    Op = "*"
                    break

                Op = chr(ord("A") + h)

        print(Op)


