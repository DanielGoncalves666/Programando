#include<iostream>
using namespace std;

int N,total,favor,voto;

int main(){
	while(cin >> N){
		total = 0;
		favor = 0;
		for(int i=0; i<N; i++){
			cin >> voto;
			if(voto == 1)
				favor++;
				
			total++;
		}
		if(favor >= total*(2.0/3.0))
			cout << "impeachment" << endl;
		else
			cout << "acusacao arquivada" << endl;
	}

	return 0;
}
