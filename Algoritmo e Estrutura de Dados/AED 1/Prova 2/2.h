
struct investimentos
{
	int codigo;
	double valor;
	float percentual;

	struct investimentos *prox;
};

typedef struct fila * Fila;

Fila cria_fila();
int fila_vazia(Fila f);
int insere_fim(Fila f, int codigo, double valor, float percentual);
int remove_ini(Fila f, struct investimentos *out);
