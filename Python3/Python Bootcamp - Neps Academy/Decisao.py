A = input()#nota de um aluno

A = float(A)#conversao para float


#em python, a condição n esta entre parenteses e apos ela há dois pontos
#alem disso, aqui a identação é obrigatorio, tudo que esta dentro do if é indicado pela identação como segue
if A >= 7:
    print("Aluno aprovado")
elif A >= 5:     #elif é o encurtamento da expresao else if
    print("Aluno de recuperação")
else:
    print("Aluno reprovado")


#em python todos os operadores booleanos, ou logicos, sao iguais ao C
#so muda o 'e', que aqui é 'and, e 'ou' que é 'or'
