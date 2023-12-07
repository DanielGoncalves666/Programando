T = input()
N = int(input())

for i in range(N):
    A = input()

    if A == "burrito":
        T = "foguento"
    elif A == "alface":
        T = "pranta"
    elif A == "cerveja":
        T = "aguado"

print(T)