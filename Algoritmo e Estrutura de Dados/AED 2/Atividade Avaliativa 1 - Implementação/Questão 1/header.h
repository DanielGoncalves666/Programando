typedef struct no * Pilha;

//pilha.c
Pilha cria_pilha();
int pilha_vazia(Pilha p);
int empilha(Pilha *p, int esq, int dir);
int desempilha(Pilha *p, int *esq, int *dir);
int le_topo(Pilha p, int *esq, int *dir);
int tamanho_pilha(Pilha p);

//preencher.c
int preencheVetor(int **vetor, int *tamanho );

//quicksort.c
void quicksort(int v[], int esq, int dir);
void quicksortAleatorizado(int v[], int esq, int dir);
void quicksortMediana3(int v[], int esq, int dir);