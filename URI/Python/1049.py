def comparar_string(a,b):
	if len(a) != len(b):
		return False
	for i in range(len(a)):
		if a[i] != b[i]:
			return False
	return True

palavra1 = input()
palavra2 = input()
palavra3 = input()

if comparar_string(palavra1,"vertebrado"):
	if comparar_string(palavra2,"ave"):
		if comparar_string(palavra3,"carnivoro"):
			print("aguia")
		elif comparar_string(palavra3,"onivoro"):
			print("pomba")
	elif comparar_string(palavra2,"mamifero"):
		if comparar_string(palavra3,"onivoro"):
			print("homem")
		elif comparar_string(palavra3,"herbivoro"):
			print("vaca") 
elif comparar_string(palavra1,"invertebrado"):
	if comparar_string(palavra2,"inseto"):
		if comparar_string(palavra3,"hematofago"):
			print("pulga")
		elif comparar_string(palavra3,"herbivoro"):
			print("lagarta")
	elif comparar_string(palavra2,"anelideo"):
		if comparar_string(palavra3,"hematofago"):
			print("sanguessuga")
		elif comparar_string(palavra3,"onivoro"):
			print("minhoca")