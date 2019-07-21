#include<stdio.h>
#include<stdlib.h>

int main()
{
    int S[20];
    int A,i,mult;

    for(i=0;i<20;i++)
        scanf("%d",&S[i]);
    scanf("%d",&A);
    for(i=0;i<20;i++)
    {
        mult=A*S[i];
        printf("%d\n",mult);
    }

    return 0;
}
