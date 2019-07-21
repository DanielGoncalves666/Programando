programa
{	inteiro numeros=12, num
	funcao inicio()
	{
		enquanto(numeros>0 e numeros<=12)
		{
			leia(num)
			numeros--
			se(num>0)
			{
				escreva("Positivo\n")
			}
			senao
			{
				se(num==0)
				{
					escreva("Nulo\n")
				}
				senao
				{
					escreva("Negativo\n")
				}
			}
		}
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 279; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */