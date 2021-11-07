/*
aluno.h
----------
Renomeação da estrutura para Aluno e protótipos das funções.
Daniel Gonçalves 2021
*/

#include <stdio.h>

typedef struct aluno Aluno;

//---Prototipos---//

Aluno *alocar();
int preencher(char *nom, double med, int falt, Aluno *p);
double pegar_media(Aluno *p);
int pegar_faltas(Aluno *p);
char *pegar_nome(Aluno *p);
void deletar(Aluno **p);