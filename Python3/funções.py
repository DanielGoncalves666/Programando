import modulo


modulo.funcao(10)

resultado = modulo.calculo(2,3)
print(resultado)

def calculo_2(x,y):
    resp = x**2 + y**2
    return resp, x**2, y**2

resultado_2 = calculo_2(5,6)

# ao usar 'resultado_2, *_' pegamos apenas o primeiro valor de retorno
#'resultado_2, quadrado_de_X, *_' --> esse ignora apenas o ultimo valor

print(resultado_2)
print(resultado_2[0])

#resultado_2 é uma tuple, n pode ser modificada