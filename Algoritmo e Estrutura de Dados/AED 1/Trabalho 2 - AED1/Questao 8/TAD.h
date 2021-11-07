typedef struct deque *Deque;

Deque cria_deque();
int deque_vazio(Deque d);
int insere_inicio(Deque d, char elem);
int insere_final(Deque d, char elem);
int remove_inicio(Deque d, char *elem);
int remove_final(Deque d, char *elem);
void apagar_deque(Deque *d);
