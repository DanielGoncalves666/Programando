#include<stdio.h>
#include<stdlib.h>

    float N,imposto=0.00;

int main(){
    scanf("%f",&N);
    if(N<=2000.00)
        printf("Isento\n");
    else{
        if(N<=3000.00){
            imposto=((N-2000.00)/100)*8;
            printf("R$ %.2f\n",imposto);
        }else{
            if(N<=4500.00){
                imposto=80.00;  //valor do imposto para a faixa 2000.01 até 3000.00
                imposto+=((N-3000.00)/100)*18;
                printf("R$ %.2f\n",imposto);
            }else{
                imposto=80.00;  //valor do imposto para a faixa 2000.01 até 3000.00
                imposto+=270.00;//valor do imposto para a faixa 3000.01 até 4500.00
                imposto+=((N-4500.00)/100)*28;
                printf("R$ %.2f\n",imposto);
            }
        }
    }
    return 0;
}
