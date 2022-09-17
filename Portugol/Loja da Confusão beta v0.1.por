programa
{	
	inteiro compras=15, codigo
	real compra, aprazo=0.0, avista=0.0, maior=0.0, menor=2147483647.0, provamenor, provamaior, total
	
	funcao inicio()
	{
		enquanto(compras>0)
		{
			leia(codigo)
			leia(compra)
			compras--
			
			provamaior=compra-maior
			provamenor=compra-menor
			
			se(codigo==1)
			{
				avista=compra+avista
				se(provamenor<=0)
				{
					menor=compra
				}
			}
			se(codigo==2)
			{
				aprazo=compra+aprazo
				se(provamaior>=0)
				{
					maior=compra
				}
			}
		}
		total=avista+aprazo
		escreva(aprazo, "\n")
		escreva(avista, "\n")
		escreva(maior, "\n")
		escreva(menor, "\n")
		escreva(total)
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 391; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */