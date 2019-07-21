programa
{	
	inteiro compras=15
	real compra, desconto, comprad
	funcao inicio()
	{
		enquanto(compras>0 e compras<=15)
		{
			leia(compra)
			compras--
			
			desconto= (compra/100)*10
			comprad= compra-desconto
			escreva(comprad, "\n")
		}
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 190; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */