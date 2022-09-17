#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct no
{
	char country[30];
	char info[25];
	struct no *esq;
	struct no *dir;
};

typedef struct no *Arv;

void inserir(Arv *a, char country[], char info[]);
char *consulta(Arv a, char country[]);

int main()
{
	char country[30], *resul;
	Arv natal = NULL;

	inserir(&natal,"brasil","Feliz Natal!");
	inserir(&natal,"alemanha","Frohliche Weihnachten!");
	inserir(&natal,"austria","Frohe Weihnacht!");
	inserir(&natal,"coreia","Chuk Sung Tan!");
	inserir(&natal,"espanha","Feliz Navidad!");
	inserir(&natal,"grecia","Kala Christougena!");
	inserir(&natal,"estados-unidos","Merry Christmas!");
	inserir(&natal,"inglaterra","Merry Christmas!");
	inserir(&natal,"australia","Merry Christmas!");
	inserir(&natal,"portugal","Feliz Natal!");
	inserir(&natal,"suecia","God Jul!");
	inserir(&natal,"turquia","Mutlu Noeller");
	inserir(&natal,"argentina","Feliz Navidad!");
	inserir(&natal,"chile","Feliz Navidad!");
	inserir(&natal,"mexico","Feliz Navidad!");
	inserir(&natal,"antardida","Merry Christmas!");
	inserir(&natal,"canada","Merry Christmas!");
	inserir(&natal,"irlanda","Nollaig Shona Dhuit!");
	inserir(&natal,"belgica","Zalig Kerstfeest!");
	inserir(&natal,"italia","Buon Natale!");
	inserir(&natal,"libia","Buon Natale!");
	inserir(&natal,"siria","Milad Mubarak!");
	inserir(&natal,"marrocos","Milad Mubarak!");
	inserir(&natal,"japao","Merii Kurisumasu!");

	while(scanf("%s",country) != EOF)
	{
		getchar();

		resul = consulta(natal,country);
		if(resul == NULL)
			printf("--- NOT FOUND ---\n");
		else
			printf("%s\n",resul);
	}

}

void inserir(Arv *a, char country[], char info[])
{
	if(*a == NULL)
	{
		Arv novo = (Arv) malloc(sizeof(struct no));
		strcpy(novo->country, country);
		strcpy(novo->info, info);
		novo->esq = novo->dir = NULL;
		*a = novo;
	}
	else
	{
		Arv aux = *a;
		if(strcmp(country,aux->country) < 0)
		{
			inserir(&(aux->esq),country,info);
		}
		else
		{
			inserir(&(aux->dir),country,info);
		}
	}
}

char *consulta(Arv a, char country[])
{
	if(a == NULL)
		return NULL;
	else
	{
		if(strcmp(a->country,country) == 0)
		{
			return a->info;
		}
		else if(strcmp(a->country,country) > 0)
		{
			return consulta(a->esq,country);
		}
		else
		{
			return consulta(a->dir,country);
		}
	}
}