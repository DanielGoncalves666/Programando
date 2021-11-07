typedef struct paciente * Paciente;
typedef struct fila * Fila;

#define QTD 30
#define MAX 20

Fila cria_fp();
int fp_vazia(Fila f);
int fp_cheia(Fila f);
int insere_ord(Fila p, char name[], int idad, int org, int grau);
int remove_ini(Fila p, char name[], int *idad, int *org, int *grau);
int esvazia_fp(Fila f);
