#include<stdio.h>
#include<stdlib.h>

int N;
char *string;

void deslocar_3(char *string);
void inverter(char *string);
int achar_ultimo_char(char *string);
void deslocar_metade(char *string);
void imprimir(char *string);

int main(){
	scanf("%d ",&N);	

	for(int i=0; i<N; i++){
		string = malloc(sizeof(char)*1001);
		fgets(string,1001,stdin);
		deslocar_3(string);
		inverter(string);
		deslocar_metade(string);

		imprimir(string);
		free(string);
	}
	
	return 0;
}

void deslocar_3(char *string){
	for(int h=0;;h++){
		if(string[h] == '\0')
			break;
				
		if( (int) string[h] >= 65 && (int) string[h] <= 90){
			//65 é a letra A em decimal segundo ASCII
			//90 é a letra Z em decimal segundo ASCII
			string[h] = (char) ( (int) (string[h] + 3));
		}else if( (int) string[h] >= 97 && (int) string[h] <= 122){
			//97 é a letra a em decimal segundo ASCII
			//122 é a letra z em decimal segundo ASCII
			string[h] = (char) ( (int) (string[h] + 3));
		}
	}
}

void inverter(char *string){
	for(int i=0,h=achar_ultimo_char(string);;i++,h--){
		if(i == h || i == h + 1){
			break;//se estiverem na mesma posição, ou se i já tiver passado h
		}
		char aux = string[i];
		string[i] = string[h];
		string[h] = aux;
	}
}

int achar_ultimo_char(char *string){
	for(int i=0;;i++){
		if(string[i] == '\0'){
			if(string[i-1] == '\n'){
				string[i-1] = '\0';
				return i - 2;
			}else
				return i - 1;
		}
	}
}

void deslocar_metade(char *string){
	int metade = (achar_ultimo_char(string) + 1)/2;
	for(int i=metade;;i++){
		if(string[i] == '\0')
			break;
		
		string[i] = (char) ( (int) (string[i] - 1));
	}
}

void imprimir(char *string){
	for(int a=0;;a++){
		if(string[a] == '\0'){
			printf("\n");
			break;		
		}
		printf("%c",string[a]);
	}
}
