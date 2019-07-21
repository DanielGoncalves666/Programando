def eh_primo(x):
    if(x == 1):
        return False
    for i in range(2,x-1):
        if(x % i == 0):
            return False
    return True

x = int(input())
if eh_primo(x):
    print('S')
else:
    print('N')