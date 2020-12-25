#include<stdio.h>
#include<math.h>

int
main()
{
	int D = 0, VF = 0, VG = 0;
	double tempo_fugir = 0.0, tempo_interceptar = 0.0;
	double hipotenusa = 0;

	while(scanf("%d %d %d", &D, &VF, &VG) != EOF)
	{
		tempo_fugir = 12.0 / VF;
		hipotenusa = sqrt(12 * 12 + D * D);
		tempo_interceptar = hipotenusa / VG;

		if(tempo_fugir < tempo_interceptar)
			printf("N\n");
		else
			printf("S\n");
	}

	return 0;
}