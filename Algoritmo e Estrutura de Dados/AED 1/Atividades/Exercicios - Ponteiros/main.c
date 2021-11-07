#include <stdio.h>

int main()
{
	//endereço de A = 1234600.

	double *p, *q, *r, A[5];//declaração das variáveis
	p = A; q = p+1; r = q+2;
	//p = 1234600; q = 1234608; r = 1234624
	printf("&A[0] = %lu; *r= %lf;\n", &A[0], *r);
	//o valor de &A[0] é 1234600; o valor de *r é o valor armazenado em A[3], que é lixo.
	printf("p= %lu; *(A+1)= %lf;\n", p, *(A+1));
	//o valor de 'p' é 1234600; o valor de *(A + 1) é lixo.
	r = p+4;p = q;
	//r = 1234632; p = q = 1234608
	printf("p+1= %lu; *(r-2)= %lf;\n", p+1, *(r-2));
	//o valor de p+1 é 1234616; o valor armazenado em *(r - 2) é o valor de A[2], que é lixo
	printf("&A[4] = %lu; *r= %lf;\n", &A, *r);
	//o endereço de A é 1234600; o valor referenciado por r é o mesmo que A[4], que é lixo.

	return (0);
}