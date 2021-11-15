#include<stdio.h>
#include<stdlib.h>

int N,seg,min,h;

int main()
{
    scanf("%d",&N);
    h=N/3600;
    N-=h*3600;
    min=N/60;
    seg=N%60;
    printf("%d:%d:%d\n",h,min,seg);

    return 0;
}
