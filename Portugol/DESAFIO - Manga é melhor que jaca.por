programa
{
	inteiro n, p, resto, metade, soma
	funcao inicio()
	{
		leia(n)
		resto=n%2
		metade=(n-resto)/2
		
		se(resto==0)
		{
			soma=metade*(n+1)
		}
		senao
		{
			soma=metade*(n+1)+n
		}
		escreva(soma)
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 113; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */