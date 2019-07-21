#include<stdio.h>
#include<stdlib.h>

float Celcius,Fahrenheit;

float convertion(int n1)
{
    float F;
    F=(9*n1+160)/5;
    return F;
}

int main()
{
    scanf("%f",&Celcius);
    Fahrenheit=convertion(Celcius);
    printf("Fahrenheit-->%.2f graus",Fahrenheit);
    return 0;
}
