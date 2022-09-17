programa
{
	inteiro num, resto5, resto7
	funcao inicio()
	{
		leia(num)
		resto5=num%5
		resto7=num%7

		se(resto5==0 e resto7==0)
		{
			escreva("O numero e multiplo de 5 e 7")
		}
		senao
		{
			escreva("O numero nao e multiplo de 5 e de 7")
		}
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 178; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */