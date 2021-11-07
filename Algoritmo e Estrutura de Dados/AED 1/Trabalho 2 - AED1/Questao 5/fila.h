struct aluno{
    int matricula;
    char nome[50];
    int ano;
    float cra;
};

#define max 20

typedef struct aluno Aluno;
typedef struct fila * Fila;

Fila cria_fila();
int fp_vazia(Fila f);
int insere_fim(Fila f, Aluno elem);
int remove_ord(Fila f, Aluno *elem);
void esvazia_fp(Fila f);
