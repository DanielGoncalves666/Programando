/*
Este programa realiza duas operações:
*a multiplicação entre duas classes de congruência dos inteiros módulo um natural.
*a multiplicação entre uma classe e todas as classes dos inteiros módulo um natural.
Para ambos os casos, o programa imprime na tela.
Daniel Gonçalves 01/2021
*/
#include<stdio.h>
#include<stdlib.h>

//PROTOTIPOS
int conversao(int modulo, int classe);
void entrada1();
void entrada2();
void escolha();
int operacao1(int modulo, int classe1, int classe2);
void operacao2(int modulo, int classe);

int
main()
{
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
A função requisita do usuárario o modulos dos inteiros e uma classe. Em seguida chama a função que realizará todas as multiplicações.
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
		printf("\nEscolha:\n1 - Uma única multiplicação entre duas classes.\n2 - A multiplicação de uma classe por todas as outros nos inteiros módulo n.\n3 - Sair.\n4 - Limpar a tela.\n");
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
				return;
			case 4:
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
Realiza a multiplicação da classe por toda classe dos interios módulo 'modulo'.
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
