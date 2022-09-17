#include<stdio.h>
#include<stdlib.h>

int num,horas;
float valorh;

int main()
{
    scanf("%d",&num);
    scanf("%d",&horas);
    scanf("%f",&valorh);

    printf("NUMBER = %d\n",num);
    printf("SALARY = U$ %.2f\n",(horas*valorh));

    return 0;
}
