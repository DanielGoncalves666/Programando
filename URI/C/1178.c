#include<stdio.h>
#include<stdlib.h>

double N[100];
double X;
int i;

int main()
{
    scanf("%lf",&X);
    for(i=0;i<100;i++)
    {
        if(i==0)
            N[i]=X;
        else
            N[i]=N[i-1]/2;
        printf("N[%d] = %.4lf\n",i,N[i]);
    }
    return 0;
}
