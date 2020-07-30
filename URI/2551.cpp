#include<iostream>
using namespace std;

int main(){
	int N;
	double tempo,dist;

	while(cin >> N){
		double menor;
		for(int i=0; i<N; i++){
			cin >> tempo >> dist;

			if(i == 0){
				cout << "1" << endl;
				menor = dist/tempo;
			}else if(menor <  dist/tempo){
				cout << i + 1 << endl;
				menor = dist/tempo;
			}
		}
	}
	return 0;
}