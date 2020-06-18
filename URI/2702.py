C,B,P = list(map(int,input().split()))
Cr,Br,Pr = list(map(int,input().split()))

nao = 0

if C < Cr:
    nao += Cr - C
if B < Br:
    nao += Br - B
if P < Pr:
    nao += Pr - P

print(nao)
