#include<iostream>
using namespace std;

int main(){
	int N, a, d, g;

	cin >> N;

	for(int i=0; i<N; i++){
		cin >> a >> d >> g;

		if(a < 200 || a > 300){
			cout << "Nao" << endl;
			continue;
		}

		if(d < 50){
			cout << "Nao" << endl;
			continue;
		}

		if(g < 150){
			cout << "Nao" << endl;
			continue;
		}

		cout << "Sim" << endl;
	}

	return 0;
}