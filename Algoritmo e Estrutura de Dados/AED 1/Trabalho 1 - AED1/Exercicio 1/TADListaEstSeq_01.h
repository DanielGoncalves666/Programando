typedef struct lista *Lista;

Lista cria_lista();
int lista_vazia(Lista);
int lista_cheia(Lista);
int insere_elem(Lista, float);
int remove_elem(Lista, float);
void libera_lista(Lista *);
void inicializa_lista(Lista);
int get_elem(Lista, int, float *);
int tamanho(Lista lst);
int retorna_maior(Lista lst, float *num);
int remove_impar(Lista lst);
int esvaziar(Lista lst);
Lista concatenar(Lista lst, Lista L2);
Lista inverter(Lista lst);
