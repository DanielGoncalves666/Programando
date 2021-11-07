typedef struct no * Lista;

Lista criar_lista();
int lista_vazia(Lista lst);
int insere_elem (Lista *lst, int elem, int tipo);
int remove_elem (Lista *lst, int elem, int tipo);