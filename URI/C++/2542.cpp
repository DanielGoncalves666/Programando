#include<iostream>
using namespace std;

int N,M,L,Cm,Cl,atributo;

int main(){
	while(cin >> N){
		cin >> M >> L;
		int Marcos[M][N];
		int Leonardo[L][N];
		for(int i=0; i<M; i++){
			for(int h=0; h<N; h++){
				cin >> Marcos[i][h];
			}
		}
		for(int i=0; i<L; i++){
			for(int h=0; h<N; h++){
				cin >> Leonardo[i][h];
			}
		}
		
		cin >> Cm >> Cl;
		cin >> atributo;
		
		if(Marcos[Cm-1][atributo-1] > Leonardo[Cl-1][atributo-1])
			cout << "Marcos\n";
		else if(Marcos[Cm-1][atributo-1] < Leonardo[Cl-1][atributo-1])
			cout << "Leonardo\n";
		else
			cout << "Empate\n";
	}

	return 0;
}
