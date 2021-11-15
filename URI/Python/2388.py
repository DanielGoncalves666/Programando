N = int(input())

total = 0
for i in range(N):
    T,V = list(map(int,input().split()))
    total += T*V

print(total)
