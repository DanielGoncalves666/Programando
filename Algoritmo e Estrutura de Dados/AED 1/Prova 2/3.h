typedef struct deque * Deque;

Deque cria_deque();
int deque_vazio(Deque d);
int deque_cheio(Deque d);
int insere_inicio(Deque d, char string[]);
int insere_final(Deque d, char string[]);
int remove_inicio(Deque d, char string[]);
int remove_final(Deque d, char string[]);
