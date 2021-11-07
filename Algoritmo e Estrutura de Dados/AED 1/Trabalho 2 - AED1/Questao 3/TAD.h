typedef struct fila * Fila;

#define QTD 11
#define MAX 10

Fila cria_fila();
int fila_vazia(Fila f);
int fila_cheia(Fila f);
int insere_fim(Fila f, char plate[], char service, int hour, int minute);
int remove_ini(Fila f, char plate[], char *service, int *hour, int *minute);
int tamanho(Fila f);