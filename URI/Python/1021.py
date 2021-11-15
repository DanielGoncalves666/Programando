N = float(input())
N = int(N * 100)#evitar erro de aproximação

print("NOTAS:")
print("{} nota(s) de R$ 100.00".format(int(N/10000)))
N = N % 10000

print("{} nota(s) de R$ 50.00".format(int(N/5000)))
N = N % 5000

print("{} nota(s) de R$ 20.00".format(int(N/2000)))
N = N % 2000

print("{} nota(s) de R$ 10.00".format(int(N/1000)))
N = N % 1000

print("{} nota(s) de R$ 5.00".format(int(N/500)))
N = N % 500

print("{} nota(s) de R$ 2.00".format(int(N/200)))
N = N % 200

print("MOEDAS:")
print("{} moeda(s) de R$ 1.00".format(int(N/100)))
N = N % 100

print("{} moeda(s) de R$ 0.50".format(int(N/50)))
N = N % 50

print("{} moeda(s) de R$ 0.25".format(int(N/25)))
N = N % 25

print("{} moeda(s) de R$ 0.10".format(int(N/10)))
N = N % 10

print("{} moeda(s) de R$ 0.05".format(int(N/5)))
N = N % 5

print("{} moeda(s) de R$ 0.01".format(int(N/1)))