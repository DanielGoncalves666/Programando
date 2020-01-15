#include<stdio.h>
#include<stdlib.h>

	int par[5], impar[5], a, i, p=0, m=0;

void main(){
	for(i=0;i<15;i++){
		scanf("%d",&a);
		if(a%2==0){
			par[p]=a;
			p++;
		}else{
			impar[m]=a;
			m++;
		}
		
		if(p==5){
			for(p=0;p<5;p++)
				printf("par[%d] = %d\n",p,par[p]);
			p=0;
		}
		if(m==5){
			for(m=0;m<5;m++)
				printf("impar[%d] = %d\n",m,impar[m]);
			m=0;
		}
	}
	if(m>0){
		for(i=0;i<m;i++)
			printf("impar[%d] = %d\n",i,impar[i]);
	}
	if(p>0){
		for(i=0;i<p;i++)
			printf("par[%d] = %d\n",i,par[i]);
	}
}
