programa
{		
	inteiro i, num, maior, menor
	
	funcao inicio()
	{
		para(i=0;i<15;i++)
		{
			leia(num)

			se(i==0)
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
					
		}
		escreva(maior, "\n")
		escreva(menor)
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta se��o do arquivo guarda informa��es do Portugol Studio.
 * Voc� pode apag�-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 316; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */