typedef struct no *Pilhac;
Pilhac cria_pilha_char();
int pilha_vazia_char(Pilhac p);
int pushchar(Pilhac *p, char elem);
int popchar(Pilhac *p, char *elem);
int le_topo_char(Pilhac *p, char *elem);
int esvazia_pilha_char(Pilhac *p);
