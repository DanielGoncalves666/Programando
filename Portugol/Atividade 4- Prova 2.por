programa
{
	inteiro n, num, somap=0, somai=0
	funcao inicio()
	{
		para(n=0;n<1;)
		{
			leia(num)
			se(num>1000)
			{
				n++
			}
			senao
			{
				se(num%2==0)
				{
					somap=num+somap
				}
				senao
				{
					somai=num+somai
				}
			}
		}
		escreva(somap, "\n")
		escreva(somai)
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta se��o do arquivo guarda informa��es do Portugol Studio.
 * Voc� pode apag�-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 293; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */