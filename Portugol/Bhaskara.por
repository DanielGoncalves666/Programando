programa
{
	
	inclua biblioteca Matematica --> mat

     real a, b, c, b2, delta, radelt, x, xx
     
	funcao inicio()
	{
		
		escreva("Boa tarde!\n")
		escreva("Seja a equa��o a*x^2+b*x+c=0:\n")
		escreva("Digite um valor para a.\n")
		leia(a)
		escreva("Digite um valor para b.\n")
		leia(b)
		escreva("Digite um valor para c.\n")
		leia(c) 
			
		b2= mat.potencia(b, 2.0)
		delta=b2-4*a*c
		radelt = mat.raiz(delta, 2.0)

		se(delta>=0)
		{
			se(delta==0)
			{
				x=(-b)/2*a
				escreva("A ra�z da express�o �:", x)
			}
			senao
			{
				x=(-b+radelt)/2*a
				xx =(-b-radelt)/2*a
				escreva("As ra�zes da express�o s�o:\n")
				escreva(x)
				escreva("\n", xx)
			}
		}
		senao
		{
			escreva("Equa��o sem solu��es.")
		}
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta se��o do arquivo guarda informa��es do Portugol Studio.
 * Voc� pode apag�-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 594; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */