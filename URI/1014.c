#include<stdio.h>
#include<stdlib.h>

int X;
double Y,cm;

int main()
{
    scanf("%d",&X);
    scanf("%f",&Y);
    cm=X/Y;
    printf("%.3f km/l\n",cm);

    return 0;
}
