programa
{	
	inteiro i, codigo
	real compra, avista=0.0, aprazo=0.0, maior, menor, total
	
	funcao inicio()
	{
		para(i=0;i<15;i++)
		{
			leia(codigo)
			leia(compra)

			se(codigo==1)
			{
				avista=compra+avista
				se(i==0)
				{
					menor=compra
				}
				senao
				{
					se(compra<menor)
					{
						menor=compra
					}
				}
			}
			se(codigo==2)
			{
				aprazo=compra+aprazo
				se(i==0)
				{
					maior=compra
				}
				senao
				{
					se(compra>maior)
					{
						maior=compra
					}
				}
			}
		}
		total=aprazo+avista
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
 * @POSICAO-CURSOR = 76; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */