idade = int(input())

anos = idade/365
idade = idade%365

meses = idade/30
dias = idade%30

print("{} ano(s)\n{} mes(es)\n{} dia(s)".format(int(anos),int(meses),int(dias)))