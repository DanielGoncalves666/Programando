#include<stdio.h>
#include<stdlib.h>

int N,n;

int main()
{
    scanf("%d",&N);
    for(N;N>0;N--)
    {
        scanf("%d",&n);
        if(n%2==0)
        {
            if(n!=0)
            {
                printf("EVEN ");
            }
            else
            {
                printf("NULL\n");
            }
        }
        else
        {
            printf("ODD ");
        }
        if(n>0)
        {
            printf("POSITIVE\n");
        }
        if(n<0)
        {
            printf("NEGATIVE\n");
        }
    }
    return 0;
}
