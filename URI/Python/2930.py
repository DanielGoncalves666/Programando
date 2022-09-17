E,D = list(map(int,input().split()))

if E > D:
    print("Eu odeio a professora!")
else:
    if(E + 3 <= D):
        print("Muito bem! Apresenta antes do Natal!")
    else:
        print("Parece o trabalho do meu filho!")
        if E + 2 < 24:
            print("TCC Apresentado!")
        else:
            print("Fail! Entao eh nataaaaal!")
