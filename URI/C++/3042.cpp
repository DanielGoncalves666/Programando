#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int M,pos;
	while(true){
		cin >> M;
		if(M == 0)
			break;

		int pos = 1, vet[3], qtd = 0;
		for(int i=0; i<M; i++){
			cin >> vet[0] >> vet[1] >> vet[2];

			if(vet[pos] == 0)
				continue;
			else{
				for(int h=0; h<3; h++){
					if(vet[h] == 0){
						qtd += abs(pos-h);
						pos = h;
						break;
					}
				}
			}
		}

		cout << qtd << endl;
	}
	
	return 0;
}