#include<iostream>
using namespace std;

int main(){
	int N,anterior,picos;
	bool ngolandia_like = true;

	cin >> N;

	int vet[N];

	for(int i=0; i<N; i++){
		cin >> vet[i];
	}

	for(int i=0; i<N; i++){
		if(i == 0){
			if(vet[0] > vet[1]){//os pares sao picos
				picos = 2;
			}else if(vet[0] < vet[1]){//os impares sao picos
				picos = 1;
			}else{
				ngolandia_like = false;
				break;
			}
			continue;
		}

		if(picos == 2){
			if(i % 2 == 1 && vet[i] >= vet[i-1]){
				ngolandia_like = false;
				break;
			}else if(i % 2 == 0 && vet[i] <= vet[i-1]){
				ngolandia_like = false;
				break;
			}
		}else{
			if(i % 2 == 1 && vet[i] <= vet[i-1]){
				ngolandia_like = false;
				break;
			}else if(i % 2 == 0 && vet[i] >= vet[i-1]){
				ngolandia_like = false;
				break;
			}
		}
	}

	if(ngolandia_like)
		cout << "1" << endl;
	else
		cout << "0" << endl;

	return 0;
}

//pico vale pico vale            picos = 2
//vale pico vale pico			 picos = 1