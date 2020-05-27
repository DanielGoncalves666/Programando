#include<stdio.h>
#include<stdlib.h>

int k,x,y,a,b;

int main(){
	while(1){
		scanf("%d",&k);
		if(k == 0)
			break;
			
		scanf("%d %d",&x,&y);
		for(int i=0; i<k; i++){
			scanf("%d %d",&a,&b);
			if(a == x || b == y)
				printf("divisa\n");
			else if(a > x && b > y)
				printf("NE\n");
			else if(a > x && b < y)
				printf("SE\n");
			else if(a < x && b > y)
				printf("NO\n");
			else
				printf("SO\n");
		}
	}

	return 0;
}
