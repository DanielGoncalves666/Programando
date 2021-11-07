typedef struct pilha *pilha;

#define max 20

pilha cria_pilha();
int pilha_vazia(pilha p);
int pilha_cheia(pilha p);
int push(pilha p, int elem);
int pop(pilha p, int *elem);
int ve_topo(pilha p, int *elem);
int esvazia_pilha(pilha p);