i = 10
print(i)
#diferente do c, em python não é necessario declarar previamente o tipo da variavel
# vc pode armazenar um inteiro, float, bool, string
#a variavel passara a armazenar o tipo equivalente a entrada q foi dada

a = 102
print(a)

print(a+i)
#print é a função utilizada para saída de dados

print("o valor da soma de a e i:",a+i)
#a sintaxe é bem parecida com a do printf em c, no exemplo acima, a frase entre aspas duplas sera imprimida e so entao a
#soma a+i é imprimida

print("o valor da soma de a e i é {}".format(a+i))
#no exemplo acima, o .format() substitui o que esta dentro de seus partenteses, no caso a+i no lugar de {} na frase entre ""

print("a soma é {} e a divisao é {}".format(a+i,a/i))
#nesse exemplo vemos que para fazer o msm que o anterior so q com dois valores basta colocar uma virgula entre eles

c=4
b=3
print("resultado da divisão {:.3f}".format(c/b))
# no c, para delimitar a quantidade de casas após a vírgula, usa-se .2f, por exeplo, para imprimir 2 casas
# aqui, entre as duas chaves que indicam o valor, coloca-se dois pontos, seguido de um ponto, a quantidade de casas e f
#{:.2f}, por exemplo

#por padrao, no fim de tod print esta impresso um /n de maneira automatica
#para mudarmos isso, basta fazer o seguinte
print(c*b, end=" ")
#o /n estaria entre as aspas duplas de end=" ", porem nesse caso o substituimos por um espaço