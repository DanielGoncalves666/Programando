typedef struct fila * Fila;

#define tam 50

Fila cria_fila();
void liberar(Fila *f);
int fila_vazia(Fila f);
int fila_cheia(Fila f);
int inseri_fim(Fila f, int elem);
int inseri_inicio(Fila f, int elem);
int remove_ini(Fila f, int *elem);
int remove_final(Fila f, int *elem);
