programa
{	
	inteiro i, id, kg, qtdkg=0, qtdid=0
	funcao inicio()
	{
		para(i=0;i<8;i++)
		{
			leia(id)
			se(id<28)
			{
				qtdid++
			}
			leia(kg)
			se(kg>90)
			{
				qtdkg++
			}
		}
		escreva(qtdkg, "\n")
		escreva(qtdid)
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 139; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */