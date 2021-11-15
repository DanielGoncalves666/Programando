N = int(input())

quebrados = 0
for i in range(N):
    l,c = list(map(int,input().split()))
    if(l > c):
        quebrados += c

print(quebrados)
