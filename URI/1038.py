codigo, qtd = input().split()
codigo = int(codigo)
qtd = int(qtd)

if codigo == 1:
	print("Total: R$ {:.2f}".format(qtd*4.00))
elif codigo == 2:
	print("Total: R$ {:.2f}".format(qtd*4.50))
elif codigo == 3:
	print("Total: R$ {:.2f}".format(qtd*5.00))
elif codigo == 4:
	print("Total: R$ {:.2f}".format(qtd*2.00))
else:
	print("Total: R$ {:.2f}".format(qtd*1.50))
