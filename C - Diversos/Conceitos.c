#include<stdio.h>  //biblioteca para entrada e saida
#include<stdlib.h> //biblioteca de opera�oes matematicas basicas
                   //para se colocar acento � necessario add uma biblioteca "locale" e arrumar uma linha dizendo que � portugues

int       a,b,soma;  //inteiro
float     r; //real

int main()                //fun��o principal
{
	                             //ponto e virgula s� n�o � necessario em linhas que logo em seguida se abre uma chave
	printf("Delicia!!!\n");      //escreva
	scanf("%d",&a);            //l�, se for inteiro=%d e se for real=%f dentro de aspas
	scanf("%d",&b);
	scanf("%f",&r);            //virgula e "e" comercial e em seguida o nome da variavel
							   //o %f sozinho mostra 10 casas decimais. para mostrar a quantidade d=que se quer de casar usa- se %.nF,
				               //"continua��o" em que n � o numero de casas
	soma=a+b;					   //scan=scanf printf=print
	printf("Soma=%d\n", soma);  // como mostrar o resultado
	printf("%d+%d=%d\n",a,b,soma);	//mostrar mais de uma variavel
								//quando se procura o erro na linha e n se acha o erro esta no ponto e virgula na linha de cima
				                //no printf nao tem o e comercial
								// == igual; != diferente;
								//maior e menor sao do mesmo jeito
								//&& -e; ||-ou
								// if= (se)             else = (senao)
	for(*;**;***)				//* inicializando a variavel; **condi��o de parada; ***implementa��o
	{
	}
								//a fun��o void n�o retorna nd
                                //se uma fun��o possui um tipo ela deve ter um retorno
                                //� possivel a existencia de mais de um return em uma fun��o desde que eles estejam
                                //em um bloco condicional

	system("pause");   //pausa o programa
	return 0;          //continua��o da anterior

}
