typedef struct no *Polimonio;

Polimonio inicializar();
int vazio(Polimonio lst);
int inserir(Polimonio lst, int poten, int coef);
int eliminar_potencia(Polimonio lst, int poten, int *retorno);
void reiniciar(Polimonio lst);
int calcular(Polimonio lst, int X);
void imprimir(Polimonio lst);