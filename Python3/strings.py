S = "isso é uma string"
SS = 'isso é uma outra string'

print(S[0])
print(type(S))
#strings em python são imutáveis, ou seja, depois de inicializada não é possivel atribuir outra frase para a string

#tamanho
print(len(S))

#troca
print(S.replace("isso","isto"))
    #sempre que for encontrado a sequencia isso, sera substituido por isto

    #o que equivale a
S.replace("isto","isso")
print(S)

#split
print(S.split())
    #divide-se a string e cria-se uma lista de strings
    #podemos passar como argumento para split o caractere que queremos que ocorre a divisão, caso nada for passado, considerara espaços em branco

#contém
print('a' in S);
    #a esta na string S?
    #recebemos True or False

for c in S:
    print(c)