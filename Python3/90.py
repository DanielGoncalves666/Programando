S = input()

vogais = ['a','e','i','o','u']
    #lista de vogais

R = ''
    #string vazia

for c in S:
    if c in vogais:
        R += c

# se uma determinada letra estiver na lista vogais, adicionamos em nossa string vazia

if R == R[::-1]:
        print('S')
else:
    print('N')