#include<stdio.h>
#include<stdlib.h>

int N,num;
int two = 0, tree = 0, forr = 0, five = 0;

int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++){
		scanf("%d",&num);
		if(num % 2 == 0)
			two++;
		if(num % 3 == 0)
			tree++;
		if(num % 4 == 0)
			forr++;
		if(num % 5 == 0)
			five++;
	}
	printf("%d Multiplo(s) de 2\n",two);
	printf("%d Multiplo(s) de 3\n",tree);
	printf("%d Multiplo(s) de 4\n",forr);
	printf("%d Multiplo(s) de 5\n",five);
	

	return 0;
}
