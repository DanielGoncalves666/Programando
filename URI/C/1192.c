#include<stdio.h>
#include<stdlib.h>

int N;
char str[4];

int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%s",str);
		if((int) str[0] == (int) str[2])
			printf("%d\n", (str[0] - '0') * (str[2] - '0'));
		else if((int) str[1] >= 65 && (int) str[1] <= 90)
			printf("%d\n", (str[2] - '0') - (str[0] - '0'));
		else
			printf("%d\n",(str[2] - '0') + (str[0] - '0'));
	}

	return 0;
}
