typedef struct deque * Deque;

Deque cria_deque();
int deque_vazio(Deque d);
int deque_cheio(Deque d);
int insere_inicio(Deque d, int elem);
int insere_final(Deque d, int elem);
int remove_inicio(Deque d, int *elem);
int remove_final(Deque d, int *elem);
void apagar_deque(Deque *d);