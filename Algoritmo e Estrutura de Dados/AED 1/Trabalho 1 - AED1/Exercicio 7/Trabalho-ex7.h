typedef struct no *Lista;

Lista criar_lista(); //Inicializa uma lista vazia

int lista_vazia(Lista lst); //Verifica se uma lista está vazia

int insere_elem(Lista *lst, char *nome); //Insere um elemento no final da lista

int remove_pos(Lista *lst, int pos, int qnt, char *nome); // Remove o elemento de uma posição e define o próximo elemento como começo da lista

int escolha_nome(Lista *lst, char *nome); //Define um determinado nome, se existente, como começo da lista

int escolha_pos(Lista *lst, int pos, char *nome); //Define uma determinada posição como começo da lista

int get_nome(Lista lst, int pos, char *nome);

int tamanho(Lista lst);

