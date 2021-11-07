#include <stdio.h>
#include <string.h>
#include "TAD.h"

#define QTD_BOXES 5

void imprimir_boxe(Fila f);
int remocao_realocacao(Fila f, char saindo[]);
int calcular_valor(int hora, int minuto, int h_a, int m_a);

int main()
{
	Fila boxes[QTD_BOXES], espera;
	int i;

	espera = cria_fila();
	if(espera == NULL)
		return -1;

	for(int i = 0; i < QTD_BOXES; i++)
	{
		boxes[i] = cria_fila();
		if(boxes[i] == NULL)
			return -1;
	}

	int escolha,retorno;
	int tam, menos_cheio, tam_atual;//tam_atual

	char placa[QTD], saindo[QTD];
	char tipo;
	int hora, minuto;

	while(1)
	{
		printf("\n----- Escolha uma das opções abaixo: -----\n");
		printf("1 - Entrar com um veículo.\n");
		printf("2 - Retirar um veículo.\n");
		printf("3 - Visualizar cenário.\n");
		printf("4 - Encerrar\n");
		scanf("%d",&escolha);

		if(escolha == 4)
			break;
	
		switch(escolha)
		{
			case 1:
				printf("\n ----- Entre com os dados do veículo: -----");
				printf("\nPlaca: ");
				scanf("%10s",placa);
				

				printf("\nTipo de servico (M - Mensal ou A - avulso): ");
				scanf(" %c",&tipo);

				if(tipo != 'A' && tipo != 'M')
				{
					printf("\n ----- Tipo de servico invalido! -----\n");
					break;
				}

				printf("\nHora e minuto de entrada, respectivamente: ");
				scanf("%d %d",&hora,&minuto);

				if(hora >= 24)
				{
					printf("\n----- Hora inválida! ------\n");
					break;
				}

				menos_cheio = -1, tam = MAX;

				for(i = 0; i < QTD_BOXES; i++)
				{
					tam_atual = tamanho(boxes[i]);
					if(tam_atual == MAX)//se o box tiver cheio, pula
						continue;

					//como nenhum BOX com tamanho maximo passara até aqui, teremos apenas boxes com menos que MAX carros
					if(tam_atual < tam)
					{
						menos_cheio = i;
						tam = tam_atual;
					}
				}

				//se menos_cheio continuar com -1, significa que os 5 boxes estão cheios
				if(menos_cheio == -1)
				{
					printf("\n----- Todos os Boxes estão cheios! -----");

					//caso a fila de espera também esteja cheia
					if(tamanho(espera) == MAX)
						printf("----- A fila de espera está cheia! Veiculo Rejeitado! -----\n");
					else
					{
						retorno = insere_fim(espera,placa,tipo,hora,minuto);
						if(retorno == 0)
						{
							printf("\n----- Falha na insercao! ----\n");
							break;
						}	
						
						printf("----- O veiculo com placa %s foi colocada na fila de espera.-----\n",placa);
					}	
				}
				else
				{
					printf("\n----- Veiculo inserido no fim do box %d -----\n",menos_cheio + 1);
					retorno = insere_fim(boxes[menos_cheio],placa,tipo,hora,minuto);
					if(retorno == 0)
					{
						printf("\n----- Falha na insercao! ----\n");
						break;
					}	
				}

				break;
			case 2:
				printf("\n ----- Entre com a placa do veículo que está saindo: ");
				scanf("%s",saindo);

				//procuramos o carro primeiro na fila de espera,pois nela só precisamos retira-lo
				retorno = remocao_realocacao(espera,saindo);
				
				if(!retorno)//caso o veiculo nao tenha sido encontrado na fila de espera
				{
					for(i = 0; i < QTD_BOXES; i++)
					{
						retorno = remocao_realocacao(boxes[i],saindo);

						if(retorno)//veiculo encontrado
						{
							if(tamanho(espera) != 0)
							{
								remove_ini(espera,placa,&tipo,&hora,&minuto);
								insere_fim(boxes[i],placa,tipo,hora,minuto);
							}

							break;
						}
					}

					if(!retorno)
						printf("\n----- Veiculo nao encontrado -----\n");
				}

				break;
			case 3:
				printf("\n");
				for(i = 0; i < QTD_BOXES; i++)
				{
					printf("Boxe %d: \n", i + 1);
					imprimir_boxe(boxes[i]);
				}
				
				printf("\nBoxe de espera:\n");
				imprimir_boxe(espera);

				break;
			default:
				printf("\n----- Opcao Invalida! -----\n");
				break;
		}


	}

	return 0;
}

/*
imprimir_boxe
-------------
Entrada: Tipo Fila
Processo: apresenta a situação do boxe (fila) passado
Saída: nenhuma
*/
void imprimir_boxe(Fila f)
{
	int i;
	int tam = tamanho(f);

	if(tam == 0)
		printf("----- Boxe vazio! ----- \n");
	else
	{
		char placa[QTD];
		char tipo;
		int hora, minuto;

		for(i = 0; i < tam; i++)
		{
			remove_ini(f,placa,&tipo,&hora,&minuto);

			printf("Placa = %s | Servico = %c | Entrada: %02d:%02d\n",placa,tipo,hora,minuto);	

			insere_fim(f,placa,tipo,hora,minuto);
		}
		printf("\n");
	}
}

/*
remocao_realocacao
-------------------
Entrada: Tipo Fila, string
Processo: procura pela presença da placa passada como string na fila e remove o veiculo caso encontrado.
Saida: 0, se o carro nao foi encontrado, 1, se o carro foi encontrado
*/
int remocao_realocacao(Fila f, char saindo[])
{
	int i;
	int valor;

	char placa[QTD];
	char tipo;
	int hora, minuto;
	int h_a, m_a;

	int tam = tamanho(f);
	for(i = 0; i < tam; i++)
	{
		remove_ini(f,placa,&tipo,&hora,&minuto);
		if(!strcmp(placa,saindo))//carro encontrado
		{
			printf("\nPlaca = %s | Servico = %c | Entrada: %02d:%02d foi retirado\n",placa,tipo,hora,minuto);
			if(tipo == 'A')
			{
				printf("\nEntre com a hora e minuto atual: \n");
				scanf("%d %d",&h_a,&m_a);
				valor = calcular_valor(hora, minuto, h_a, m_a);
				printf("\n----- O valor total a ser pago é de %d reais. -----\n",valor);
			}
			return 1;
		}

		insere_fim(f,placa,tipo,hora,minuto);
	}

	return 0;
}

/*
calcular_valor
-------------------
Entrada: Quatro inteiros
Processo: calculo o valor a ser pago
Saida: retorna o valor a ser pago
*/
int calcular_valor(int hora_entrada, int minuto_entrada, int hora_atual, int minuto_atual)
{
	int qtd_min = 0, qtd_horas = 0, valor = 0;

	if(hora_entrada == hora_atual)
	{
		if(minuto_entrada == minuto_atual)
			valor = 79;
		else if(minuto_entrada < minuto_atual){
			valor = 10;
		}else if(minuto_entrada > minuto_atual){
			valor = 76;
			
			qtd_min += minuto_atual + (60 - minuto_entrada);
			if(qtd_min >= 15)
				valor += 3;
		}
		
		return valor;
	}
	else if(hora_entrada < hora_atual)
	{
		qtd_min += 60 - minuto_entrada;
		qtd_min += minuto_atual;

		qtd_horas += (hora_atual - (hora_entrada + 1));
	}
	else if(hora_entrada > hora_atual)
	{
		qtd_min += 60 - minuto_entrada;
		qtd_min += minuto_atual;
		
		qtd_horas += (24 - (hora_entrada + 1));
		qtd_horas += hora_atual;
	}

	if(qtd_min > 60)
	{
		qtd_min -= 60;
		qtd_horas++;
	}

	if(qtd_horas == 0)
		valor = 10;
	else
	{
		valor = 10 + (qtd_horas - 1) * 3;
		if(qtd_min >= 15)
			valor += 3;
	}
	
	return valor;
}
