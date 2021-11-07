typedef struct lista *Lista;

Lista cria_lista();
int lista_vazia(Lista li);
int lista_cheia(Lista li);
int menor_data(Lista li, Pessoa *elem);
int maior_idade(Lista li, char local[11], Pessoa *elem);
int getPos(Lista li, int pos, Pessoa *elem);
