#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int N,a,b;
char nome1[101], nome2[101], jog1[6], jog2[6];

int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++){
		scanf("%s %s %s %s",nome1,jog1,nome2,jog2);
		scanf("%d %d",&a,&b);
		
		if((a+b)%2 == 0){
			if(strcmp(jog1,"PAR") == 0)
				printf("%s\n",nome1);
			else
				printf("%s\n",nome2);
		}else{
			if(strcmp(jog1,"IMPAR") == 0)
				printf("%s\n",nome1);
			else
				printf("%s\n",nome2);
		}
	}

	return 0;
}
