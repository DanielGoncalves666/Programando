programa
{	
	inteiro nasc, idade
	funcao inicio()
	{
		leia(nasc)
		idade=2017-nasc

		se(idade<=0)
		{
			escreva("Idade inexistente")
		}
		senao
		{
			se(idade<12)
			{
				escreva("Crianca")
			}
			senao
			{
				se(idade<18)
				{
					escreva("Adolescente")
				}
				senao
				{
					se(idade<70)
					{
						escreva("Adulto")
					}
					senao
					{
						escreva("Idoso")
					}
				}
			}
		}
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta se��o do arquivo guarda informa��es do Portugol Studio.
 * Voc� pode apag�-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 102; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */