programa
{
	inteiro num, resto5, resto7
	funcao inicio()
	{
		leia(num)
		resto5=num%5
		resto7=num%7

		se(resto5==0)
		{
			se(resto7==0)
			{
				escreva("o numero e multiplo de 5\n")
				escreva("o numero e multiplo de 7")
			}
			senao
			{
				escreva("o numero e multiplo de 5\n")
				escreva("o numero nao e multiplo de 7")
			}
		}
		senao
		{
			se(resto7==0)
			{
				escreva("o numero nao e multiplo de 5\n")
				escreva("o numero e multiplo de 7")
			}
			senao
			{
				escreva("o numero nao e multiplo de 5\n")
				escreva("o numeo nao e multiplo de 7")
			}
		}
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 571; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */