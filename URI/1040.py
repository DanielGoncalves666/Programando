lista = input().split()

media = (float(lista[0])*2 + float(lista[1])*3 + float(lista[2])*4 + float(lista[3]))/10
print("Media: {:.1f}".format(media))

if media >= 7.0:
	print("Aluno aprovado.")
elif media < 5.0:
	print("Aluno reprovado.")
else:
	print("Aluno em exame.")
	exame = float(input())
	print("Nota do exame: {:.1f}".format(exame))

	media = (media + exame)/2
	if media >=5.0:
		print("Aluno aprovado.")
	else:
		print("Aluno reprovado.")

	print("Media final: {:.1f}".format(media))