A,B = input().split()

A = float(A)
B = float(B)

media = (A+B)/2

if media >= 7.0:
    print("Aprovado")
elif media >= 4.0:
    print("Recuperacao")
else:
    print("Reprovado")