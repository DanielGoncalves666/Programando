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
			escreva("N�mero inv�lido")
		}
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta se��o do arquivo guarda informa��es do Portugol Studio.
 * Voc� pode apag�-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 187; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */