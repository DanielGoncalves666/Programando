#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	int N,a,b,c;
	double delta, result;
	scanf("%d",&N);

	for(int i=0; i<N; i++){
		scanf("%d %d %d",&a,&b,&c);
		delta = pow(b,2) - 4 * a * c;
		result = -delta / (4.0 * a);

		printf("%.2f\n",result);
	}

	return 0;
}