i = int(input())

cont=1;

for h in range(i):
    for l in range(0,3):
        print("{}".format(cont), end=' ')
        cont = cont + 1

    print("PUM",end='\n')
    cont = cont + 1