N = int(input())

for i in range(N):
    N,k = list(map(int,input().split()))
    if N < k:
        print(N)
    elif N == k:
        print("1")
    else:
        extras = N // k
        print("{}".format(extras + N%k))
