programa
{	
	inteiro x, t=1, r
	funcao inicio()
	{
		leia(x)

		se(x>=0 e x<=10)
		{
			enquanto(t<=10)
			{
				r=x*t
				escreva(x)
				escreva(" X ")
				escreva(t)
				escreva(" = ")
				escreva(r, "\n")
				t++
			}
		}
		senao
		{
			escreva("Número inválido")
		}
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 187; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */