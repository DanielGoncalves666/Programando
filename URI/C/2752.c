#include<stdio.h>
#include<string.h>

int main(){
    char string[51] = "AMO FAZER EXERCICIO NO URI\0";
    printf("<%s>\n",string);
    printf("<%30s>\n",string);
    printf("<%.20s>\n",string);
    printf("<%-20s>\n",string);
    printf("<%-30s>\n",string);
    printf("<%.30s>\n",string);
    printf("<%30.20s>\n",string);
    printf("<%-30.20s>\n",string);

    return 0;
}
