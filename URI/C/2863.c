#include<stdio.h>

int main(){
    int N;
    double menor,num;
    while(scanf("%d",&N) != EOF){
        for(int i=0; i<N; i++){
            scanf("%lf",&num);
            if(i == 0)
                menor = num;
            else if(menor > num)
                menor = num;
        }
        printf("%.2lf\n",menor);
    }
    return 0;
}
