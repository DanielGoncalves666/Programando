while(1):
    try:
        N = int(input())
        menor = 0
        for i in range(N):
            num = float(input())
            if i == 0:
                menor = num
            elif menor > num:
                menor = num
        print("{:.2f}".format(menor))
    except EOFError:
        break;
