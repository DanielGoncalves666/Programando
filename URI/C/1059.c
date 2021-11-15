#include<stdio.h>
#include<stdlib.h>

int i;

int main()
{
    for(i=1;i<=100;i++)
    {
        if(i%2==0)
        {
          printf("%d\n",i);
        }
    }

    return 0;
}
