typedef struct lt *Lista;

int contem(Lista l, char elem);

Lista insere_ord(Lista l, char elem);

Lista criar_lista();

Lista remove_elem(Lista l, char elem);

Lista limpa_lista(Lista l);

Lista remove_pares(Lista l);

Lista intercalar(Lista l1, Lista l2);

int tamanho(Lista l);

int lista_vazia(Lista l);

int lista_cheia(Lista l);

char menor(Lista l);

char get_posicao(Lista l, int posicao);


