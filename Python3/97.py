import math

N = int(input())
X = input().split()

for i in range(N):
    print("{:.4f}".format(math.sqrt(float(X[i]))))