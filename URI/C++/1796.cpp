#include<iostream>
using namespace std;

int main(){
	int Q, V, sim=0, nao=0;

	cin >> Q;

	for(int i=0; i<Q; i++){
		cin >> V;

		if(V == 0)
			sim++;
		else if(V == 1)
			nao++;
	}

	if(sim > nao)
		cout << "Y\n";
	else
		cout << "N\n";
	
	return 0;
}