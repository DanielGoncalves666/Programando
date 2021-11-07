typedef struct no *Lista;

Lista cria_lista();
int lista_vazia(Lista lst);
int insere(Lista *lst, int elem);
int remov(Lista *lst, int elem);
int obtem_valor(Lista lst, int pos);
int tamanho(Lista lst);
int iguais(Lista lst, Lista lst2);
int maior(Lista lst);
int esvaziar(Lista *lst);
Lista intercala(Lista lst, Lista lst2);
