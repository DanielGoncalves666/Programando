programa
{	
	inteiro i
	real media, id, soma=0.0, qtd=0.0
	
	funcao inicio()
	{
		para(i=0;i<1;)
		{
			leia(id)
			se(id>0)
			{
				soma=id+soma
				qtd++
			}
			se(id==0)
			{
				i++
			}
		}
		media=soma/qtd
		escreva(media)
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 59; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */