/*
	Alexandre Justo Petusk Filipe - 11911BCC032
	Daniel Gonçalves - 12011BCC011	
	Luiz Fellipe Machado Tristão -12011BCC037

	Ao montar é necessário incluir a biblioteca math.h na linha de comando.
	Para executar, é necessário passar como primeiro argumento o arquivo fonte e como segundo, o arquivo destino. 
		Cuidado. O arquivo de destino será sobreescrito se já existir.
	
	Máximo de 255 caracteres por linha
	Labels tem um tamanho máximo de 25 caracteres
	O uso de .data, .text e qualquer outro que comece com . não é suportado.
		A quebra dessas regras resultará em comportamento desconhecido.
		
	Instruções com argumentos errados causarão erros inesperados.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int endereco = 0;// armazena o endereco da proxima instrução

// lista de instruções já processadas
typedef struct instrucaoTraduzida
{
	int has_label;
	int instruct_adress;
	char label[26];
	char cod[33];
	
	struct instrucaoTraduzida *prox;
}instrucaoTraduzida;
typedef instrucaoTraduzida *Traduzida;

typedef struct filaInstrucoes
{
	Traduzida ini;
	Traduzida fim;
}filaInstrucoes;


typedef struct label
{
    int label_adress;
    char label_name[26];
    
    struct label *prox;
}Label;
typedef Label * pontLabel;


typedef struct listaRegInstr
{
	char *nome;
	char *identificador;
} listaRegInstr;

typedef enum instruction_classification
{
	label_isolada,
    three_registers,
    two_registers_shamt,
    two_registers,
    one_register,
    two_registers_constant,
    two_registers_constant_memory,
    two_registers_label,
    one_registers_constant,
    one_label,
    invalido
} tipoInstrucao;

pontLabel ListaDeLabels = NULL;
filaInstrucoes *ListaDeInstrucoes = NULL;

listaRegInstr listaReg[] = {
							 {"$zero","00000"},
							 {"$at","00001"},
							 {"$v0","00010"},
							 {"$v1","00011"},
							 {"$a0","00100"},
							 {"$a1","00101"},
							 {"$a2","00110"},
							 {"$a3","00111"},
							 {"$t0","01000"},
							 {"$t1","01001"},
							 {"$t2","01010"},
							 {"$t3","01011"},
							 {"$t4","01100"},
							 {"$t5","01101"},
							 {"$t6","01110"},
							 {"$t7","01111"},
							 {"$s0","10000"},
							 {"$s1","10001"},
							 {"$s2","10010"},
							 {"$s3","10011"},
							 {"$s4","10100"},
							 {"$s5","10101"},
							 {"$s6","10110"},
							 {"$s7","10111"},
							 {"$t8","11000"},
							 {"$t9","11001"},
							 {"$k0","11010"},
							 {"$k1","11011"},
							 {"$gp","11100"},
							 {"$sp","11101"},
							 {"$fp","11110"},
							 {"$ra","11111"}							
						   };

listaRegInstr listaR[] = {
						{"add", "100000"},	// usam os três registradores
						{"sub", "100010"},
						{"and", "100100"},
						{"or",  "100101"},
						{"nor", "100111"},
						{"xor", "100110"},
						{"slt", "000000"}, 
						{"sll", "000010"}, // usam dois registradores e o shampt
						{"mul", "011000"}, // usam dois registradores
						{"div", "011010"}, 
						{"mflo","010010"}, // usam um registrador
						{"mfhi","010000"}, 
                        {"jr",  "001000"}, 
					  };

listaRegInstr listaI[] = {
					     {"addi","001000"}, // usam dois registradores e uma constante
					     {"andi","001100"},
					     {"ori", "001101"},
					     {"xori","001110"},
						 {"lw",  "100011"}, // usam dois registradores, uma constante e faz acesso à memória
					  	 {"sw",  "101011"},					     
					     {"beq", "000100"}, // dois registradores e uma label 
					     {"lui", "001111"}  // um registrador e uma constante
					  };

listaRegInstr listaJ[] = {
						 {"j",  "000010"}, // usam uma label
						 {"jal","000011"}
					  };

int quebrarLinha(char *linha);
void montarStringR(Traduzida nova, char rs[], char rt[], char rd[], char shampt[], char function[]);
void montarStringI(Traduzida nova, char opcode[], char rs[], char rt[], char constLabel[]);
tipoInstrucao identificar_instrucao(char *token, char *identifier);
int insere_elem_label(pontLabel *lst, int endereco, char *arg1);
char *tratar_registradores(char *token, char *number);
void insere_elem_instruct(filaInstrucoes *ListaDeInstrucoes, Traduzida nova);
void converter_constante(int valor, char constante[], int length);
int endereco_label(char label[]);
void complementoDeDois(char retorno[]);

// dois argumentos na linha de comando, arquivo de origem e arquivo de destino
int main(int argc, char *argv[])
{
	FILE *origem = NULL;
	FILE *destino = NULL;

	if(argc != 3)
	{
		fprintf(stderr, "Quantidade inválida de parâmetros.\n");
		return 0;
	}
	else
	{
		origem = fopen(argv[1],"r"); // abre o arquivo passado como parâmetro na linha de comando no modo de escrita.
		if(origem == NULL)
		{
			fprintf(stderr, "O arquivo não existe.\n");
			return 0;
		}
	}
	
	char linha[256];
	char label[27];
	int retorno, relativo;
	int i;
	
	ListaDeInstrucoes = malloc(sizeof(filaInstrucoes));
	ListaDeInstrucoes->ini = NULL;
	ListaDeInstrucoes->fim = NULL;
	
	while(fscanf(origem, "%[^\n] ", linha) != EOF)
	{
		retorno = quebrarLinha(linha);
		
		// erro de sintaxe encontrado
		if(!retorno)
			return 0;
	}
	
	fclose(origem);

	Traduzida aux = ListaDeInstrucoes->ini;
	while(aux != NULL)
	{
		if(aux->has_label == 1)
		{
			retorno = endereco_label(aux->label);
			
			if(retorno == -1)
			{
				fprintf(stderr,"A label %s não foi definida em local algum.\n",aux->label);
				return 0;
			}
		
			relativo = (retorno - aux->instruct_adress); // relativo à instrução
			
			if( strncmp(aux->cod,"000100",6) == 0) // beq, a label é menor
				converter_constante(relativo, label, 16);
			else	// instruções do tipo J
				converter_constante(relativo, label, 26);
			
			strcat(aux->cod, label);
		}
		
		aux = aux->prox;
	}
	
	destino = fopen(argv[2],"w+");
	if(destino == NULL)
	{
		fprintf(stderr, "Falha na criação do arquivo de destino\n");
		return 0;
	}
	
	aux = ListaDeInstrucoes->ini;
	while(aux != NULL)
	{
		fwrite(aux->cod,sizeof(char),32,destino);
		fwrite("\n",sizeof(char),1,destino);
		aux = aux->prox;
	}	
	fclose(destino);
	
	return 0;
}

int endereco_label(char label[])
{
	pontLabel aux = ListaDeLabels;
	while(aux != NULL)
	{
		if (strcmp(label,aux->label_name) == 0)
		{
			return aux->label_adress;
		}
		
		aux = aux->prox;
	} 
	
	return -1;
}

void complementoDeDois(char retorno[])
{
	int length = strlen(retorno);
	int i;
	
	for(i = 0; i < length; i++)
	{
		if(retorno[i] == '0')
			retorno[i] = '1';
		else
			retorno[i] = '0';
	}
	
	for(i = length - 1; i >= 0; i--)
	{
		if(retorno[i] == '1')
			retorno[i] = '0';
		else
		{
			retorno[i] = '1';
			break;
		}
	}
}

int insere_elem_label(pontLabel *lst, int endereco, char *arg1)
{
    pontLabel N = (pontLabel) malloc(sizeof(Label));
    if (N == NULL) 
    { 
    	return 0; 
    }

    N->label_adress = endereco; 
	strncpy(N->label_name,arg1,strlen(arg1) - 1);
   
    N->prox = *lst;
    *lst = N;
   
    return 1;
}

void insere_elem_instruct(filaInstrucoes *ListaDeInstrucoes, Traduzida nova)
{
	if(ListaDeInstrucoes->ini == NULL)
	{
		ListaDeInstrucoes->ini = ListaDeInstrucoes->fim = nova;
	}
	else
	{
		ListaDeInstrucoes->fim->prox = nova;
		ListaDeInstrucoes->fim = nova;
	}
}

int quebrarLinha(char *linha)
{
	char *token, *arg1, *arg2, *arg3;
	char identifier[7], number1[6], number2[6], number3[6], constante[17];
	tipoInstrucao op;
	Traduzida nova;
	
	token = strtok (linha, " ,");
	while(token != NULL)
	{	
		op = identificar_instrucao(token,identifier);

		switch(op)
		{
			case label_isolada:
				insere_elem_label(&ListaDeLabels,endereco,token);
				
				break;
			case three_registers:
				arg1 = strtok(NULL," ,");
				arg2 = strtok(NULL," ,");
				arg3 = strtok(NULL," ,");

				nova = (Traduzida) malloc(sizeof(instrucaoTraduzida));
				
				nova->has_label = 0;
				nova->instruct_adress = endereco;
				montarStringR(nova, tratar_registradores(arg2,number2), tratar_registradores(arg3,number3),tratar_registradores(arg1,number1), "00000", identifier);
				nova->prox = NULL;
				
				insere_elem_instruct(ListaDeInstrucoes,nova);
				
				endereco++;
				break;
			case two_registers_shamt:
				arg1 = strtok(NULL," ,");
				arg2 = strtok(NULL," ,");
				arg3 = strtok(NULL," ,");

				nova = (Traduzida) malloc(sizeof(instrucaoTraduzida));
				
				nova->has_label = 0;
				nova->instruct_adress = endereco;
				converter_constante(atoi(arg3),constante,5);// converte uma constante para binário, com bits sobressalentes zerados	
				montarStringR(nova, tratar_registradores(arg2,number2), tratar_registradores(arg1,number1), "00000" , constante, identifier);
				nova->prox = NULL;

				insere_elem_instruct(ListaDeInstrucoes,nova);

				endereco++;
				break;
			case two_registers:
				arg1 = strtok(NULL," ,");
				arg2 = strtok(NULL," ,");
				
				nova = (Traduzida) malloc(sizeof(instrucaoTraduzida));
				
				nova->has_label = 0;
				nova->instruct_adress = endereco;
				montarStringR(nova,tratar_registradores(arg1,number1), tratar_registradores(arg2,number2), "00000", "00000", identifier);
				nova->prox = NULL;
	
				insere_elem_instruct(ListaDeInstrucoes,nova);	
				
				endereco++;		
				break;
			case one_register:	
				arg1 = strtok(NULL," ,");
			
				nova = (Traduzida) malloc(sizeof(instrucaoTraduzida));
				
				nova->has_label = 0;
				nova->instruct_adress = endereco;
				montarStringR(nova, tratar_registradores(arg1,number1), "00000", "00000", "00000", identifier);
				nova->prox = NULL;

				insere_elem_instruct(ListaDeInstrucoes,nova);
			
				endereco++;	
				break;
			case two_registers_constant:
				arg1 = strtok(NULL," ,");
				arg2 = strtok(NULL," ,");	
				arg3 = strtok(NULL," ,");		
				
				nova = (Traduzida) malloc(sizeof(instrucaoTraduzida));									
				
				nova->has_label = 0;
				nova->instruct_adress = endereco;
				converter_constante(atoi(arg3),constante,16);// converte uma constante para binário, com bits sobressalentes zerados	
				montarStringI(nova, identifier, tratar_registradores(arg1,number1), tratar_registradores(arg2,number2), constante);
				nova->prox = NULL;

				insere_elem_instruct(ListaDeInstrucoes,nova);

				endereco++;				
				break;
			case two_registers_constant_memory:
				arg1 = strtok(NULL," ,");
				arg2 = strtok(NULL," ,()");	
				arg3 = strtok(NULL," ,()");		
				
				nova = (Traduzida) malloc(sizeof(instrucaoTraduzida));									
				
				nova->has_label = 0;
				nova->instruct_adress = endereco;
				converter_constante(atoi(arg2),constante,16);// converte uma constante para binário, com bits sobressalentes zerados	
				montarStringI(nova, identifier, tratar_registradores(arg1,number1), tratar_registradores(arg3,number3), constante);
				nova->prox = NULL;

				insere_elem_instruct(ListaDeInstrucoes,nova);

				endereco++;				
				break;
			case two_registers_label:
				arg1 = strtok(NULL," ,");
				arg2 = strtok(NULL," ,");
				arg3 = strtok(NULL," ,");

				nova = (Traduzida) malloc(sizeof(instrucaoTraduzida));									
				
				nova->has_label = 1;
				nova->instruct_adress = endereco;
				montarStringI(nova, identifier, tratar_registradores(arg2,number2), tratar_registradores(arg1,number1), "");
				strncpy(nova->label,arg3, strlen(arg3));
				nova->prox = NULL;

				insere_elem_instruct(ListaDeInstrucoes,nova);

				endereco++;												
				break;
			case one_registers_constant:
				arg1 = strtok(NULL," ,");
				arg2 = strtok(NULL," ,");

				nova = (Traduzida) malloc(sizeof(instrucaoTraduzida));									
				
				nova->has_label = 0;
				nova->instruct_adress = endereco;
				converter_constante(atoi(arg2),constante,16);// converte uma constante para binário, com bits sobressalentes zerados	
				montarStringI(nova, identifier,"00000", tratar_registradores(arg1,number1), constante);
				nova->prox = NULL;

				insere_elem_instruct(ListaDeInstrucoes,nova);

				endereco++;								
				break;
			case one_label:
				arg1 = strtok(NULL," ,");

				nova = (Traduzida) malloc(sizeof(instrucaoTraduzida));
				
				nova->has_label = 1;
				nova->instruct_adress = endereco;
				strcpy(nova->cod,identifier); //coloca o opcode
				strncpy(nova->label,arg1, strlen(arg1));
				nova->prox = NULL;

				insere_elem_instruct(ListaDeInstrucoes,nova);

				endereco++;
				break;
			case invalido:	
				// erro
				fprintf(stderr, "O mnemônico %s é inválido.\n", token);
				return 0;
				
				break;
		}
		
		token = strtok(NULL," ,");
	}
	
	return 1;
}
				
void montarStringR(Traduzida nova, char rs[], char rt[], char rd[], char shampt[], char function[])
{
	strcpy(nova->cod,"000000"); //coloca o opcode
	strcat(nova->cod, rs); // coloca o primeiro registrador
	strcat(nova->cod, rt); // coloca o segundo registrador
	strcat(nova->cod, rd); // coloca o registrador de destino
	strcat(nova->cod, shampt); // coloca o shampt
	strcat(nova->cod, function); // coloca o function
}

void montarStringI(Traduzida nova, char opcode[], char rs[], char rt[], char constLabel[])
{
	strcpy(nova->cod, opcode); //coloca o opcode
	strcat(nova->cod, rs); // coloca o primeiro registrador
	strcat(nova->cod, rt); // coloca o segundo registrador
	strcat(nova->cod, constLabel); // coloca a constante ou label
}

// length não inclui \0
void converter_constante(int valor, char constante[], int length)
{
	int i = 0, h;
	int resto, aux = valor < 0? (-valor) : valor;
	char buffer;
	
	while(aux != 0)
	{
		resto = aux % 2;
		aux /= 2;
		
		constante[i] = resto == 1 ? '1' : '0';
		i++;
	}
	
	for(; i < length; i++)
	{
		constante[i] = '0';
	}
	constante[i] = '\0';
	
	// inverte a string
	for(i = 0, h = length - 1; i < h; i++, h--)
	{
		buffer = constante[i];
		constante[i] = constante[h];
		constante[h] = buffer;
	}	
	
	if(valor < 0) // a string acima foi calculada usando um número positivo, em caso de valor se negativo precisamos fazer complemneto de 2 agora
		complementoDeDois(constante);
}

char *tratar_registradores(char *token, char *number)
{
	int i;

	for(i = 0; i < 32; i++)
	{
		if(strcmp(token,listaReg[i].nome) == 0)
		{
			strcpy(number,listaReg[i].identificador);
			return number;
		}
	}
	
	strcpy(number,"-----");
	return number; // casos de erro
}


tipoInstrucao identificar_instrucao(char *token, char identifier[])
{
	int i;
	
	if( token[strlen(token) - 1] == ':')		// labels
		return label_isolada;
	
	for(i = 0; i < 13; i++) 					// instruções R
	{
		if(strcmp(token, listaR[i].nome) == 0)
		{
			strcpy(identifier, listaR[i].identificador);
			
			if(i <= 6)
				return three_registers; 				// instruções que usam os três registradores
			else if(i == 7)
				return two_registers_shamt;		     	// instruções que usam dois registradores e o shampt
			else if(i <= 9)
				return two_registers;					// instruções que usam dois registradores
			else
				return one_register;					// instruções que usam um registrador
		}
	}
	
	for(i = 0; i < 8; i++)						// instruções I
	{
		if(strcmp(token, listaI[i].nome) == 0)
		{
			strcpy(identifier, listaI[i].identificador);
		
			if(i <= 3)
				return two_registers_constant;			// instruções que usam dois registradores e uma constante
			else if(i <= 5)
				return two_registers_constant_memory;			// instruções que usam dois registradores e uma constante e fazem acesso à memória
			else if(i == 6)
				return two_registers_label;				// dois registradores e uma label
			else
				return one_registers_constant;			// um registrador e uma constante
		}
	}
	
	for(i = 0; i < 2; i++)						// instruções J
	{
		if(strcmp(token, listaJ[i].nome) == 0)
		{
			strcpy(identifier, listaJ[i].identificador);
			
			return one_label; 							// usam uma label
		}
	}
	
	return invalido;								    // token inválido
}
