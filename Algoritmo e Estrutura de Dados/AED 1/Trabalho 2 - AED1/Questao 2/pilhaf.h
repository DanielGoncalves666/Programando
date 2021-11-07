typedef struct no *Pilha;
Pilha cria_pilha();
int pilha_vazia(Pilha p);
int push(Pilha *p, float elem);
int pop(Pilha *p, float *elem);
int le_topo(Pilha *p, float *elem);
int esvazia_pilha(Pilha *p);
