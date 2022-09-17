programa
{	
	inteiro n=7, num, maior, menor
	
	funcao inicio()
	{
		enquanto(n>0)
		{
			leia(num)

			se(n==7)
			{
				maior=num
				menor=num
			}
			senao
			{
				se(num>maior)
				{
					maior=num
				}
				se(num<menor)
				{
					menor=num
				}
			}	
			n--
		}
		escreva(maior, "\n")
		escreva(menor)
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 38; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */