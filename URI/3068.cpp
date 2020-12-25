#include<iostream>
using namespace std;

int
main()
{
	int x1,y1,x2,y2;
	int x,y;
	int teste = 1;
	int qtd;
	int N;


	while(1){
		cin >> x1 >> y1 >> x2 >> y2;

		if(x1+y1+x2+y2 == 0) 
			break;

		cin >> N;

		qtd = 0;
		for(int i = 0; i < N; i++)
		{
			cin >> x >> y;

			if((x >= x1 && x <= x2) && (y <= y1 && y >= y2))
			{
				qtd++;
			}
		}
		cout << "Teste " << teste << "\n";
		teste++;
		cout << qtd << endl;
	}

	return 0;
}