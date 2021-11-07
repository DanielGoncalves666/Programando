typedef struct no *Lista;

Lista cria_lista();
int lista_vazia(Lista lst);
int insere_ord(Lista lst, double elem);
int remov(Lista lst, double elem);
int obtem_valor_elem(Lista lst, int pos, double *valor);
int tamanho(Lista lst);
int iguais(Lista lst, Lista lst2);
int maior(Lista lst, double *maior);
void esvaziar(Lista lst);
Lista intercala(Lista lst, Lista lst2);