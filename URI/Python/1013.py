a,b,c = input().split()
a = int(a)
b = int(b)
c = int(c)

if a>b and a>c:
	print("{} eh o maior".format(a))
elif b>c:
	print("{} eh o maior".format(b))
else:
	print("{} eh o maior".format(c))