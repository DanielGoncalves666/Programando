#include<stdio.h>

int main()
{
    printf("int: %d bytes\n",sizeof(int));                          //short necessita de 2 bytes
    printf("short int: %d bytes\n",sizeof(short int));              //long e int necessitam de 4 bytes
    printf("long int: %d bytes\n",sizeof(long int));
    printf("signed int: %d bytes\n",sizeof(signed int));
    printf("unsigned int: %d bytes\n",sizeof(unsigned int));
    printf("short signed int: %d bytes\n",sizeof(short signed int));
    printf("short unsigned int: %d bytes\n",sizeof(short unsigned int));
    printf("long signed int: %d bytes\n",sizeof(long signed int));
    printf("long unsigned int: %d bytes\n",sizeof(long unsigned int));

    printf("\nfloat: %d bytes\n",sizeof(float));                   //float necessita de 4 bytes
    printf("double: %d bytes\n",sizeof(double));                   //double necessita de 8 bytes

    return 0;
}
