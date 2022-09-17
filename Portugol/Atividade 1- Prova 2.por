programa
{	
	inteiro i=0, kg, id, qtdkg=0, qtdid=0
	funcao inicio()
	{
		enquanto(i<8)
		{
			leia(id)
			leia(kg)

			se(kg>90)
			{
				qtdkg++
			}
			se(id<28)
			{
				qtdid++
			}
			i++
		}
		escreva(qtdkg, "\n")
		escreva(qtdid)
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 118; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */