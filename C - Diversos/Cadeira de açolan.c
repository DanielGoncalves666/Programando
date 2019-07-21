#include<stdlib.h>
#include<stdio.h>

int main()
{

    int n1, soma1=0, soma2=0;

    while(n1<=999)
    {
        scanf("%d",&n1);

        if(n1%2==0)
        {
            soma1=soma1+n1;
            continue;
        }
        if(n1%2==1)
            soma2=soma2+n1;
    }
    printf("Soma par: %d\n",soma1);
    printf("Soma impar: %d\n",soma2);
    return 0;
}
