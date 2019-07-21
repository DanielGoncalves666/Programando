programa
{	
	inteiro n=15, num, qtd1=0, qtd2=0
	funcao inicio()
	{
		enquanto(n>0)
		{
			leia(num)
			n--

			se(num<35)
			{
				qtd1++
			}
			se(num>80)
			{
				qtd2++
			}
		}
		escreva(qtd1)
		escreva("\n", qtd2)
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 125; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */