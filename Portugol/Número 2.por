programa
{	
	inteiro i, num, qtdnum=0, qtdpar=0
	funcao inicio()
	{	
		para(i=0;i<1;)
		{
			leia(num)
			se(num==1000)
			{
				i++
			}
			senao
			{	
				qtdnum++
				se(num%2==0)
				{
					qtdpar++
				}
			}
		}
		escreva(qtdnum, "\n")
		escreva(qtdpar)
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta se��o do arquivo guarda informa��es do Portugol Studio.
 * Voc� pode apag�-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 142; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */