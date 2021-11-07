typedef struct data{
    short int dia, mes, ano;
}Data;

typedef struct pessoa{
    char nome[50];
    int idade;
    short int comorbidade; //1 sim ou 0 nao
    char tipoVacina;
    Data primeiraDose, segundaDose;
    char localVacinacao[11];
} Pessoa;

typedef struct fila *Fila;

Fila cria_fila();
int fila_vazia(Fila f);
int insere_fim(Fila f, Pessoa elem);
int remove_ini(Fila f, Pessoa *elem);
void apaga_fila(Fila f);
void esvazia_fila(Fila f);
int tamanho(Fila f);
