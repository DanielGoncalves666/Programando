#include "grafo.h"
#include "pilha.h"
#include "fila.h"
#include <stdlib.h>
#include <stdio.h>

// Retorna o endereço em sucesso, NULL em fracasso.
Grafo criarGrafo(int nVert)
{
  int i;

  Grafo G = (Grafo) malloc(sizeof(struct grafo));
  if(G == NULL)
    return NULL;

  G->NumVert = 0;
  G->NumArestas = 0;
  G->vertices = NULL;

  for(i = nVert - 1; i >= 0; i--)
  {
    G->vertices = inserirVertice(G->vertices,i);
    G->NumVert++;
  }

  return G;
}

struct noVert *inserirVertice(struct noVert *ini, int num)
{
  struct noVert *no = (struct noVert *) malloc(sizeof(struct noVert));
  no->vert = num;
  no->prox = ini;
  no->ladj = NULL;

  return no;
}

void inserirNovoVertice(Grafo G, int nv)
{
  G->vertices = inserirVertice(G->vertices,nv);
  G->NumVert++;
}

//0 em fracasso, 1 em sucesso
int inserirArco(Grafo G, int v1, int v2)
{
  struct noVert *v;
  struct noAdj *z;
  
  if(G == NULL)
    return 0;
  
  for(v = G->vertices; v != NULL; v = v->prox)
  {
    if(v1 == v->vert)//vértice encontrado
    {
      for(z = v->ladj; z != NULL; z = z->prox)
      {
        //vértice já existe na adjacencia
        if(v2 == z->vert)
          return 0;
      
      v->ladj = inserirAdjacencia(v2, v->ladj);
      G->NumArestas++;
                   
      }
    }
  }

  return 1;
}

struct noAdj *inserirAdjacencia(int v2, struct noAdj *ldj)
{
  struct noAdj *novo = (struct noAdj*) malloc(sizeof (struct noAdj));
  novo->vert = v2;
  novo->lhorarios = NULL;//nenhum horário definido no momento de criação.
  novo->prox = ldj;

  return novo;
}

//0 em fracasso, 1 em sucesso
int inserirHorario(Grafo G, int v1, int v2, int hi, int mi, int hf, int mf)
{
  struct noVert *vertice;
  struct noAdj *adjacente;

  if(G == NULL)
    return 0;

  for(vertice = G->vertices; vertice != NULL; vertice = vertice->prox)
  {
    //encontra o vértice de saída
    if(v1 == vertice->vert)
    {
      for(adjacente = vertice->ladj; adjacente != NULL; adjacente = adjacente->prox)
      {
        //encontra o vértice de entrada  
        if(v2 == adjacente->vert)
        {
          //não há problema em ter horários repetidos ou que se sobrepoẽm para um mesmo destino. Pode-se ter mais de um ônibus saindo no mesmo horário por causa da demanda e um ônibus pode demorar mais por causa das paradas no caminho.
          //para indicar uma rota que sai de uma cidade e vai até outra, atravessando por uma cidade é necessário setar saida / chagada = saida/ chegada.

          adjacente->lhorarios = inserirNovoHorario(adjacente->lhorarios, hi,mi,hf,mf);
          return 1;
        }
        else
          return 0;
      }
    }
  }

  return 0;
}

struct noHorario *inserirNovoHorario(struct noHorario *lh, int hi, int mi, int hf, int mf)
{
  struct noHorario *novo = (struct noHorario *) malloc(sizeof(struct noHorario));

  novo->HoraSaida = hi;
  novo->MinutoSaida = mi;
  novo->HoraChegada = hf;
  novo->MinutoChegada = mf;
  novo->prox = lh;

  return novo;
}

//como estamos pensando em um grafo direcional, mas que em todos os casos tem ambos sentidos, a função procurará pelos vértices passados ao mesmo tempo até achar o primeiro e então verificar se ocorre ligação com o outro.
//0 para não, 1 para sim
int existeAresta(Grafo G, int v1, int v2)
{
  struct noVert *vertice;
  struct noAdj *adjacente;

  for(vertice = G->vertices; vertice != NULL; vertice = vertice->prox)
  {
    //encontra o vértice de saída
    if(v1 == vertice->vert)
    {
      for(adjacente = vertice->ladj; adjacente != NULL; adjacente = adjacente->prox)
      {
        //encontra o vértice de entrada  
        if(v2 == adjacente->vert)
        {
          return 1;
        }
      }
    }
    else if(v2 == vertice->vert)
    {
      for(adjacente = vertice->ladj; adjacente != NULL; adjacente = adjacente->prox)
      {
        //encontra o vértice de entrada  
        if(v2 == adjacente->vert)
        {
          return 1;
        }
      }
    }
  }

  return 0;
}

//ao contrário da função que verifica a existência das arestas, aqui a ordem importa. Verificaremos os horários que existem de v1 até v2.

struct noHorario *encontrarListaHorarios(Grafo G, int v1, int v2)
{
  struct noVert *vertice;
  struct noAdj *adjacente;

  for(vertice = G->vertices; vertice != NULL; vertice = vertice->prox)
  {
    //encontra o vértice de saída
    if(v1 == vertice->vert)
    {
      for(adjacente = vertice->ladj; adjacente != NULL; adjacente = adjacente->prox)
      {
        //encontra o vértice de entrada  
        if(v2 == adjacente->vert)
        {
            return adjacente->lhorarios;
        }
      }
    }
  }
  
  return NULL;//caso não exista nenhum horário entre as cidades naquele sentido
}

//horário mais cedo para chegada no outro vértice
int horarioPrimeiraChegada(struct noHorario *lh, int *h, int *m)
{
  if(lh == NULL)
    return 0;

  *h = lh->HoraChegada;
  *m = lh->MinutoChegada;
  
  for(;lh != NULL; lh = lh->prox)
  {
    if(lh->HoraChegada < *h)
    {
       *h = lh->HoraChegada;
       *m = lh->MinutoChegada;
    }else if(lh->HoraChegada < *h)
    {
      if(lh->MinutoChegada < *m)
      {
        *h = lh->HoraChegada;
        *m = lh->MinutoChegada;
      }
    }
  }

  return 1;
}

//horário mais cedo para saída
int horarioPrimeiraSaída(struct noHorario *lh, int *h, int *m)
{
  if(lh == NULL)
    return 0;

  *h = lh->HoraSaida;
  *m = lh->MinutoSaida;
  
  for(;lh != NULL; lh = lh->prox)
  {
    if(lh->HoraSaida < *h)
    {
       *h = lh->HoraSaida;
       *m = lh->MinutoSaida;
    }else if(lh->HoraSaida < *h)
    {
      if(lh->MinutoSaida < *m)
      {
        *h = lh->HoraSaida;
        *m = lh->MinutoSaida;
      }
    }
  }

  return 1;
}

//tempo calculado em minutos
int calculaTempoDuracao(int hi, int mi, int hf, int mf)
{
  int total = 0;

  if(hi < hf)
  {
    total = (hf - (hi + 1)) * 60 + (60 - mi) + mf;
  }
  else if(hi > hf)
  {
    total = (24 - (hi + 1) + hf) * 60 + (60 - mi) + mf;
  }
  else
  {
    if(mi < mf)
    {
      total = mf - mi;
    }else if(mi > mf)
    {
      total = 23 * 60 + (60 - mi) + mf;
    }
    else
      total = 24 * 60;
  }
  
  return total;
}

void viagemDuracaoMaisCurta(struct noHorario *lh, int *hs, int *ms, int *hc, int *mc)
{
  *hs = lh->HoraSaida;
  *ms = lh->MinutoSaida;
  *hc = lh->HoraChegada;
  *mc = lh->MinutoChegada;

  int duracao = calculaTempoDuracao(*hs,*ms,*hc,*mc), aux;

  lh = lh->prox;
  for(; lh != NULL; lh = lh->prox)
  {
    if( (aux = calculaTempoDuracao(*hs,*ms,*hc,*mc)) < duracao)
    {
      *hs = lh->HoraSaida;
      *ms = lh->MinutoSaida;
      *hc = lh->HoraChegada;
      *mc = lh->MinutoChegada;

      duracao = aux;
    }
  }
}

void imprimirListaAdj(Grafo G) { 
   struct noVert *nv;
   struct noAdj *na;
   if (G == NULL) return;
   printf("\n\nLista de Adjacencias:");
   for (nv = G->vertices; nv!=NULL; nv = nv->prox) {
      printf("\nVertice %d:",nv->vert);
      for (na = nv->ladj; na != NULL; na = na->prox)
          printf("(%d)",na->vert); 
   }    
}


/*
void imprimirListaAdjRec(struct noVert *nv) { 
   struct noAdj *na;
   if (nv == NULL) return;
   printf("\nVertice %d:",nv->vert);
   for (na = nv->ladj; na != NULL; na = na->prox)
          printf("(%d)",na->vert); 
   imprimirListaAdjRec(nv->prox);      
}


int grauVertice(Grafo G, int v) { 
   struct noVert *nv;
   struct noAdj *na;
   int cont = 0;
   if (G == NULL) return 0;
   for (nv = G->vertices; nv!=NULL; nv = nv->prox) {
      if(v == nv->vert){
         for (na = nv->ladj; na != NULL; na = na->prox)
             cont = cont + 1;  // grau de saída
      }
      else{
         for (na = nv->ladj; na != NULL; na = na->prox)
             if(v == na->vert)
               cont = cont + 1; // grau de entrada
      }       
   }   
   return cont; 
}






int imprimeVisita(int *vet, int tam){
  int i;
  printf("\nOrdem da visita: ");
  for (i = 0; i<=tam; i++){
     printf("(%d) ", vet[i]);
  }
  return 0;
}



void BuscaEmProfundidade (Grafo G, int v) {
   struct noVert *nv;
   struct noAdj *na;
   int *visitados;
   TipoPilha *pilha;
   int i=0, cont = 0, vt;

   //Iniciar o vetor de visitados com -1 para todos os vértices
   visitados = (int *) malloc (G->NumVert * sizeof (int));
   for (i=0; i<G->NumVert; i++){
      visitados[i] = -1;
   }
   //Iniciar a fila e inserir o vértice de origem
   pilha = (TipoPilha *) malloc (sizeof(TipoPilha));
   IniciaPilha(pilha);
   Empilha(v,pilha);
   
   while(!VaziaPilha(pilha)){
       vt = Desempilha(pilha);
       if (FoiVisitado(vt,visitados,cont)==0){
          visitados[cont]=vt;
          cont++;
          for (nv = G->vertices; nv!=NULL; nv = nv->prox) 
              if(vt == nv->vert)
                 for (na = nv->ladj; na != NULL; na = na->prox)
                      if (FoiVisitado(na->vert,visitados,cont)==0){
                           Empilha(na->vert,pilha);
                      }
       }
   }
   imprimeVisita(visitados,cont-1);
   free(pilha);
}



int MarcaVisitaTempo(int vt, int pos, char tipo, struct visitaTempo *vet, int tam){
  int i;
  for (i = 0; i<tam; i++){
    if(vet[i].vert == vt){
         if (tipo == 'D'){
             vet[i].tempoDescoberta = pos;
             return 1;
         }   
         else{
             if (vet[i].tempoFinalizacao == -1){
                 vet[i].tempoFinalizacao = pos;
                 return 1;
             }
             else return 0;
         }       
    }           
  }
  return 0;
}

int FoiVisitadoTempo(int vert, struct visitaTempo *vet, int tam){
  int i;
  for (i = 0; i<tam; i++){
    if((vet[i].vert == vert) && (vet[i].tempoDescoberta != -1))
       return 1;
  }
  return 0;
}

int imprimeVisitaTempo(struct visitaTempo *vet, int tam){
  int i;
  for (i = 0; i<tam; i++){
     printf("\n(%d) Descoberta: %d, Finalizacao: %d", 
         vet[i].vert, vet[i].tempoDescoberta, vet[i].tempoFinalizacao);
  }
  return 0;
}


void PercursoProfundidadeTempo (Grafo G, int v) {
   struct noVert *nv;
   struct noAdj *na;
   struct visitaTempo *visitados;
   TipoPilha *pilha;
   int tam=0, cont = 0, vt, finaliza, r;

   //Iniciar o vetor de visitados com -1 para todos os vértices
   visitados = (struct visitaTempo *) malloc (G->NumVert * sizeof (struct visitaTempo));
   for (nv=G->vertices; nv!=NULL; nv=nv->prox){
      visitados[tam].vert = nv->vert;
      visitados[tam].tempoDescoberta = -1;
      visitados[tam].tempoFinalizacao = -1;
      tam++;
   }
   //Iniciar a fila e inserir o vértice de origem
   pilha = (TipoPilha *) malloc (sizeof(TipoPilha));
   IniciaPilha(pilha);
   Empilha(v,pilha);

   while(!VaziaPilha(pilha)){
       vt = Topo(pilha);
       if (FoiVisitadoTempo(vt,visitados,tam)==0){
          MarcaVisitaTempo(vt, cont++, 'D', visitados,tam);
          //cont++;
          for (nv = G->vertices; nv!=NULL; nv = nv->prox) 
              if(vt == nv->vert){
                 finaliza = 1;
                 for (na = nv->ladj; na != NULL; na = na->prox)
                      if (FoiVisitadoTempo(na->vert,visitados,tam)==0){
                           Empilha(na->vert,pilha);
                           finaliza = 0;
                      }
                 if (finaliza == 1){
                     r = MarcaVisitaTempo(vt,cont,'F',visitados,tam);
                     if (r == 1) cont++;
                     vt = Desempilha(pilha);
                 }
              }        
       }
       else {
           r = MarcaVisitaTempo(vt,cont,'F',visitados,tam);
           if (r == 1) cont++;
           vt = Desempilha(pilha);
       }
   }
   imprimeVisitaTempo(visitados,tam);
   free(pilha);
}

*/