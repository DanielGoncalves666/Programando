struct cliente
{
	char nome[50];
	int agencia;
	int numeroConta;
	int tipo;//1 -- corrente, 2 -- poupança
};

void quicksort_mediana_tres(struct cliente v[], int esq, int dir);
void mergesortMelhorado(struct cliente v[], int esq, int dir);