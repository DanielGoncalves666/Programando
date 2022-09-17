A,B,C = input().split()
A = int(A)
B = int(B)
C = int(C)

ganhador = '*'

if A != B and A != C:
    ganhador = 'A'
elif B != A and B != C:
    ganhador = 'B'
elif C != A and C != B:
    ganhador = 'C'
else:
    ganhador = '*'

print("{}".format(ganhador))