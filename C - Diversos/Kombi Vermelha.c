#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i=1000;
    while(i<2000)
    {
        if(i%11==5)
            printf("%d\n",i);

        i++;
    }

    return 0;
}
