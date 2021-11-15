N = int(input())

if N == 1:
	print("Top 1")
elif N <= 3:
	print("Top 3")
elif N <= 5:
	print("Top 5")
elif N <= 10:
	print("Top 10")
elif N <= 25:
	print("Top 25")
elif N <= 50:
	print("Top 50")
else:
	print("Top 100")