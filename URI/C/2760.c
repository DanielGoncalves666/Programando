#include<stdio.h>
#include<string.h>

int main(){
    char string1[101], string2[101], string3[101];
    scanf("%[^\n]s",string1);
    getchar();
    scanf("%[^\n]s",string2);
    getchar();
    scanf("%[^\n]s",string3);
    printf("%s%s%s\n",string1,string2,string3);
    printf("%s%s%s\n",string2,string3,string1);
    printf("%s%s%s\n",string3,string1,string2);
    printf("%.10s%.10s%.10s\n",string1,string2,string3);

    return 0;
}
