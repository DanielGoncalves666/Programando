salario = float(input())
novo_salario = 0
p = 0

if salario >= 0.0 and salario <= 400.00:
	novo_salario = salario + (salario * 0.15)
	p = 15
elif salario >= 400.01 and salario <= 800.00:
	novo_salario = salario + (salario * 0.12)
	p = 12
elif salario >= 800.01 and salario <= 1200.00:
	novo_salario = salario + (salario * 0.1)
	p = 10
elif salario >= 1200.01 and salario <= 2000.00:
	novo_salario = salario + (salario * 0.07)
	p = 7
elif salario > 2000.00:
	novo_salario = salario + (salario * 0.04)
	p = 4

print("Novo salario: {:.2f}".format(novo_salario))
print("Reajuste ganho: {:.2f}".format(novo_salario - salario))
print("Em percentual: {} %".format(p))