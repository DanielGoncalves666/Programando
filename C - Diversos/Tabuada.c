#include<stdio.h>
#include<stdlib.h>

int main()
{
    int num,m,i;
    scanf("%d",&num);
    for(i=1;i<=10;i++)
    {
        m=num*i;
        printf("%d X %d = %d\n",num,i,m);
    }


    return 0;
}
