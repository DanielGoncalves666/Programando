#include<stdio.h>
#include<string.h>

int main(){
    int a;
    float b;
    char c, string[51];
    scanf("%d %f %c %[^\n]s",&a,&b,&c,string);
    printf("%d%.6f%c%s\n",a,b,c,string);
    printf("%d\t%.6f\t%c\t%s\n",a,b,c,string);
    printf("%10d%10.6f%10c%10s\n",a,b,c,string);


    return 0;
}
