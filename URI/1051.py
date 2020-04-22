salario = float(input())

if salario <= 2000.00:
	print("Isento")
elif salario > 2000.00 and salario <= 3000.00:
	print("R$ {:.2f}".format((salario - 2000.00)*0.08))
elif salario > 3000.00 and salario <= 4500.00:
	print("R$ {:.2f}".format((1000.00)*0.08 + (salario - 3000.00)*0.18))
elif salario > 4500.00:
	print("R$ {:.2f}".format((1000.00)*0.08 + (1500.00)*0.18 + (salario - 4500.00)*0.28))