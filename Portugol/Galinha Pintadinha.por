programa
{	
	inteiro num, i, resto, somapares=0, somaimpa=0
	
	funcao inicio()
	{
		para(i=1;i>0;)
		{
			leia(num)

			se(num>1000)
			{
				i--
			}
			senao
			{
				resto=num%2
				se(resto==0)
				{
					somapares=num+somapares
				}
				se(resto==1)
				{
					somaimpa=num+somaimpa
				}
			}
		}
		escreva(somapares, "\n")
		escreva(somaimpa)
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 303; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */