typedef struct fila * Fila;

#define tam 30

Fila cria_fila();
int fila_vazia(Fila f);
int insere(Fila f, int elem);
int remove_ini(Fila f, int *elem);
void apaga_fila(Fila *f);
int esvazia_fila(Fila f);