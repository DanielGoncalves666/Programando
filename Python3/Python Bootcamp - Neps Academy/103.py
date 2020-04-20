N = int(input())
a = input().split()

for i in range(N):
    a[i] = int(a[i])

a.sort()

for i in range(N):
    if(i == N-1):
        print(a[i])
    else:
        print(a[i], end = ' ')
