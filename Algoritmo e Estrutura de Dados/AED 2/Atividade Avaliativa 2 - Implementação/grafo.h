struct grafo
{
  int NumVert;
  int NumArestas;
  struct noVert *vertices;//lista de vértices.
};
typedef struct grafo *Grafo;

struct noVert
{
  int vert;
  struct noVert *prox;//próximo vértice
  struct noAdj *ladj;//lista de adjacência
};

struct noAdj
{
  int vert;//Número do vértice
  struct noHorario *lhorarios; //lista de horarios  
  struct noAdj *prox;//proximo nó adjacente 
};

struct noHorario
{
  int HoraSaida, MinutoSaida;
  int HoraChegada, MinutoChegada;
  struct noHorario *prox;//lista de horários
};

Grafo criarGrafo(int nVert);
struct noVert *inserirVertice(struct noVert *ini, int num);
void inserirNovoVertice(Grafo G, int nv);
int inserirArco(Grafo G, int v1, int v2);
struct noAdj *inserirAdjacencia(int v2, struct noAdj *ldj);
int inserirHorario(Grafo G, int v1, int v2, int hi, int mi, int hf, int mf);
struct noHorario *inserirNovoHorario(struct noHorario *lh, int hi, int mi, int hf, int mf);
struct noHorario *encontrarListaHorarios(Grafo G, int v1, int v2);
int existeAresta(Grafo G, int v1, int v2);
int horarioPrimeiraChegada(struct noHorario *lh, int *h, int *m);
int horarioPrimeiraSaída(struct noHorario *lh, int *h, int *m);
int calculaTempoDuracao(int hi, int mi, int hf, int mf);
void viagemDuracaoMaisCurta(struct noHorario *lh, int *hs, int *ms, int *hc, int *mc);

void imprimirListaAdj(Grafo G);



/*

struct visitaTempo{
  int vert;
  int tempoDescoberta;
  int tempoFinalizacao;
};


 A lista de adjacência de um vértice v é composta por nós. Cada nó da  corresponde a um arco e contém um vizinho w de v e o endereço do nó seguinte da lista. 

Grafo criarGrafo(int nVert);
void inserirArco(Grafo G, int v1, int v2);
void inserirNovoVertice(Grafo G, int nv);
int grauVertice(Grafo G, int v);
void imprimirListaAdj(Grafo G);
void imprimirListaAdjRec(struct noVert *nv);

void BuscaEmLargura(Grafo G, int v);
void BuscaEmProfundidade (Grafo G, int v);
void PercursoProfundidadeTempo (Grafo G, int v);
*/