/*
Este programa realiza as seguintes operações:
*a multiplicação entre duas classes de congruência dos inteiros módulo um natural.
*a multiplicação entre uma classe e todas as classes dos inteiros módulo um natural.
*a "simplificação" de uma classe de congruência, convertendo ela em uma classe 0<=r<'modulo'
*a conversão de uma classe de congruência negativa em uma classe 0<-r<'modulo'
O programa sempre imprime o resultado na tela

Daniel Gonçalves 01/2021
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//PROTOTIPOS
int conversao(int modulo, int classe);
void entrada1();
void entrada2();
void entrada3();
void entrada4();
void entrada5();
void escolha();
int operacao1(int modulo, int classe1, int classe2);
void operacao2(int modulo, int classe);
void operacao3(int modulo, int classe, int qtd_expoente);

int
main()
{
	system("clear");
	escolha();

	return 0;
}

/*
conversao
----------
A função recebe como parâmetros o modulo dos inteiros e uma classe, retornando a classe convertida para um valor entre 0<=r<'modulo'.
*/
int 
conversao(int modulo, int classe)
{
	return classe % modulo;
}

/*
entrada
---------
A função não recebe nenhum argumento e não retorna nada.
Requisita do usuário o modulo dos inteiros e duas classes, chamando uma função para multiplicá-los e então apresenta o resultado.
*/
void
entrada1()
{
	int modulo = 0;//modulo dos inteiros
	int classe1 = 0;//primeira classe
	int classe2 = 0;//segunda classe
	int result = 0;//armazena o resultado da multiplicação
	
	printf("Entre, respectivamente, com o módulo dos inteiros, a primeira classe e a segunda classe:\n");
	scanf("%d %d %d",&modulo, &classe1, &classe2);

	result = operacao1(modulo,classe1,classe2);	

	printf("\nClasse %10d  *  Classe %10d  =  Classe %10d\n",classe1,classe2,result);
}


/*
entrada2
---------
A função não recebe nada e retorna nada.
A função requisita do usuário o modulos dos inteiros e uma classe. Em seguida chama a função que realizará todas as multiplicações.
*/
void
entrada2()
{
	int modulo = 0;//modulo dos inteiros
	int classe = 0;//armazena a classe
	
	printf("Entre, respectivamente, com o módulo dos inteiros e a classe:\n");
	scanf("%d %d",&modulo,&classe);

	operacao2(modulo,classe);
}

/*
entrada3
---------
A função não recebe nada e não retorna nada.
Requisita do usuário o módulo dos inteiros e uma classe, realizando a "simplificação" dessa classe.
*/
void
entrada3()
{
	int modulo = 0;//modulo dos inteiros
	int classe = 0;//armazena a classe
	int result = 0;//resultado da simplificação
	
	printf("Entre, respectivamente, com o módulo dos inteiros e a classe:\n");
	scanf("%d %d",&modulo,&classe);
	
	result = conversao(modulo,classe);
	
	printf("\nClasse %10d  =  Classe %10d \t nos inteiros módulo %d\n",classe,result,modulo);
}

/*
entrada4
---------
A função não recebe nenhum parâmetro e não retorna nenhuma valor.
Requisita do usuário o módulo dos inteiros e uma classe negativa, retornando esta simplificada e positiva.
*/
void
entrada4()
{
	int modulo = 0;//modulo dos inteiros
	int classe_neg = 0;//armazena a classe negativa
	int result = 0;//resultado da simplificação
	
	printf("Entre, respectivamente, com o módulo dos inteiros e a classe que está negativa:\n");
	scanf("%d %d",&modulo,&classe_neg);
	
	if(classe_neg >= 0){
		printf("Essa classe não é negativa.\n");
		return;
	}
		
	result = - conversao(modulo,-classe_neg);
	//passamos a classe como positiva para simplificação pois não importa se ela está simplificada ou não, o resultado da conversão de negativo para uma classe 0<=r<'modulo' é igual. Depois convertemos o valor recebido para negativo novamente
	//Com a simplificação feita, tenho certeza que o modulo do número que representa a classe de congruência negativa é menor que o módulo dos inteiros
	
	result = result + modulo;
	//classe_neg = -1 . modulo + result
	
	printf("\nClasse %10d  =  Classe %10d \t nos inteiros módulo %d\n",classe_neg,result,modulo);

}

/*
entrada5
--------
A função não recebe nenhum dado como parâmetro e retorna nenhum valor.
Requisita do usuário o módulo dos inteiros, a classe e a quantidade de potências a serem mostradas. Os expoentes são na forma de 2*n, com 0<n<=qtd.

*/
void
entrada5()
{
	int modulo = 0;//modulo dos inteiros
	int classe = 0;//classe
	int qtd_expoente = 0;//qtd de potências
	
	printf("Entre, respectivamente, com o módulo dos inteiros, a classe e a quantidade de potências:\n");
	scanf("%d %d %d",&modulo,&classe,&qtd_expoente);
	
	operacao3(modulo,classe,qtd_expoente);
}

/*
escolha
-----------
A função não recebe nenhum valor e não retorna nada.
A função requisita do usuário a escolha da operação a ser realizada e então chama a função específica.
*/
void 
escolha()
{
	int num = 0;//armazena a opção escolhida pelo usuário
	
	while(1)
	{
		printf("\nEscolha:\n1 - Uma única multiplicação entre duas classes.\n2 - A multiplicação de uma classe por todos os representantes nos inteiros módulo n.\n3 - Converter uma classe para um dos representantes 0<=r<'modulo'.\n4 - Converter uma classe negativa para um dos representados 0<=r<'modulo'.\n5 - As 'n' primeiras potências de uma classe na forma 'a'^(2*n).\n6 - Sair.\n7 - Limpar a tela.\n");
		scanf("%d",&num);
		switch(num)
		{
			case 1:
				entrada1();
				break;
			case 2:
				entrada2();
				break;
			case 3:
				entrada3();
				break;
			case 4:
				entrada4();
				break;
			case 5:
				entrada5();
				break;
			case 6:
				return;
			case 7:
				system("clear");
				break;
			default:
				printf("Valor não reconhecido. Tente novamente!\n");
				break;
		}
	}
}

/*
operacao1
----------
A função recebe como parâmetros o modulo dos inteiros e duas classes. Retorn o result já simplificado da multiplicação das classes.
*/
int
operacao1(int modulo, int classe1, int classe2)
{
	int result = 0;//armazena a multiplicação

	if(classe1 >= modulo)
		classe1 = conversao(modulo,classe1);
		
	if(classe2 >= modulo)
		classe2 = conversao(modulo,classe2);
		
	result = classe1 * classe2;
	
	if(result >= modulo)
		result = conversao(modulo,result);
		
	return result;
}

/*
operacao2
----------
A função recebe o modulo dos inteiros e uma classe, mas não retorna nada.
Realiza a multiplicação da classe por toda classe dos inteiros módulo 'modulo'.
*/
void
operacao2(int modulo, int classe)
{
	int result = 0;//resultado da multiplicação
	
	if(classe >= modulo)
		classe = conversao(modulo,classe);
		
	for(int i = 0; i < modulo; i++)
	{
		result = classe * i;
		
		if(result >= modulo)
			result = conversao(modulo,result);
	
		printf("\nClasse %10d  *  Classe %10d  =  Classe %10d\n",classe,i,result);
	}
}

/*
operacao3
----------
A função recebe como parâmetros o modulo dos inteiros, a classe e a quantidade de potências a serem mostradas.
Não retorna nada.
Apresenta ao usuário as 'qtd_expoente' primeiras potências da classe, excetuando 'classe'^0.
*/
void
operacao3(int modulo, int classe, int qtd_expoente)
{
	int aux = 0;
	
	if(classe >= modulo){
		aux = conversao(modulo,classe);
		printf("\nClasse %10d  =  Classe %10d \t nos inteiros módulo %d\n",classe,aux,modulo);
		classe = aux;
	}
			
	printf("\nClasse %10d  ^  %5d  =  Classe %10d\n",classe,1,classe);//2^0 = 1
	
	aux = classe;
	for(int i = 1; i <= qtd_expoente; i++)//começa em 2^1 = 2
	{
		aux = operacao1(modulo,aux,aux);
		
		printf("\nClasse %10d  ^  %5d  =  Classe %10d\n",classe,(int) pow(2,i),aux);
	}
}
