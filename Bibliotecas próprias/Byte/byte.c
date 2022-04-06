#include"byte.h"

/*
inverter_bit
--------------
Entrada: unsigned char, contendo o byte a ser manipulado
	     inteiro sem sinal, contendo a posição do bit que deve ser invertida (0 até 7, da esquerda para a direita)
Descrição: inverte o bit no byte 'b' na posição 'pos'
Saída: o byte 'b' alterado.
*/
unsigned char inverterBit(unsigned char b, unsigned int pos)
{	
	return b ^ (128U >> pos); 
}


/*
status_bit
-------------
Entrada: unsigned char, contendo o byte a ser consultado
	     inteiro sem sinal, contendo a posição do bit que deve ser consultada (da esquerda para a direita)
Descrição: consulta o valor do bit na posição 'pos' do byte 'b'
Saída: o valor do bit na posição 'pos'
*/
int statusBit(unsigned char b, unsigned int pos)
{
	if((b & (128U >> pos)) > 0)
		return 1;
	else 
		return 0;
}

/*
localizarBitEsquerda
---------------------
Entrada: unsigned char, contendo o byte a ser consultado
		 inteiro, 0 faz a função por pelo primeiro 0, qualquer outro valor faz a função buscar pelo primeiro 1
Descrição: realiza a busca no byte 'b' pela primeira posição com o valor 'bit' (da esquerda para a direita)
Saída: inteiro, indicando a posição onde o primeiro bit com o valor de 'bit' se encontra, ou -1, se não for encontrado.
*/
int localizarBitEsquerda(unsigned char b, short int bit)
{
	int i;

	if(bit != 0)
	{
		for(i = 0; i < 8; i++)
		{
			if( (b & (128U >> i)) > 0)
			{
				// encontrou o primeiro 1 da esquerda pra direita
				return i;
			}
		}	
	}
	else
	{
		for(i = 0; i < 8; i++)
		{
			if( (b & (128U >> i)) == 0)
			{
				// encontrou o primeiro 0 da esquerda pra direita
				return i;
			}
		}
	}
		
	return -1;
}


/*
localizarBitDireita
---------------------
Entrada: unsigned char, contendo o byte a ser consultado
		 inteiro, 0 faz a função por pelo primeiro 0, qualquer outro valor faz a função buscar pelo primeiro 1
Descrição: realiza a busca no byte 'b' pela primeira posição com o valor 'bit' (da direita pra a esquerda)
Saída: inteiro, indicando a posição onde o primeiro bit com o valor de 'bit' se encontra, ou -1, se não for encontrado.
*/
int localizarBitDireita(unsigned char b, short int bit)
{
	int i;

	if(bit != 0)
	{
		for(i = 0; i < 8; i++)
		{
			if( (b & (1U << i)) > 0)
			{
				// encontrou o primeiro 1 da direita pra esquerda
				return (7 - i);
			}
		}
		
	}
	else
	{
		for(i = 0; i < 8; i++)
		{
			if( (b & (1U << i)) == 0)
			{
				// encontrou o primeiro 0 da direita pra esquerda
				return (7 - i);
			}
		}
	}
	
	return -1;
}

