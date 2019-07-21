programa
{	
	inteiro p, id, peso, qtd=0, idvelha, idnova
	real alt, soma=0.0, media
	funcao inicio()
	{
		para(p=0;p<25;p++)
		{
			leia(id)
			leia(alt)
			leia(peso)

			se(peso>50)
			{
				qtd++
			}

			soma=alt+soma

			se(p==0)
			{
				idvelha=id
				idnova=id
			}
			senao
			{
				se(id>idvelha)
				{
					idvelha=id
				}
				se(id<idnova)
				{
					idnova=id
				}
			}
		}
		media=soma/25
		escreva(qtd, "\n")
		escreva(media, "\n")
		escreva(idnova, "\n")
		escreva(idvelha)
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 373; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */