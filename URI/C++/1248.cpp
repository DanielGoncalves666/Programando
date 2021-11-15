#include<iostream>
#include<string>
using namespace std;

int main(){
	int N;
	string dieta, cafe, almoco;
	bool encontrado, cheater;

	cin >> N;
	getchar();

	for(int i=0; i<N; i++){
		cin >> dieta >> cafe >> almoco;

		for(int i=0; i<cafe.size(); i++){
			encontrado = false;
			for(int h=0; h<dieta.size(); h++){
				if(cafe[i] == dieta[h]){
					dieta[h] = '.';
					encontrado = true;
					break;
				}

			}
			if(encontrado == false){
				cheater = true;
				goto aqui;
			}
		}

		for(int i=0; i<almoco.size(); i++){
			encontrado = false;
			for(int h=0; h<dieta.size(); h++){
				if(almoco[i] == dieta[h]){
					dieta[h] = '.';
					encontrado = true;
					break;
				}

			}
			
			if(encontrado == false){
				cheater = true;
				break;
			}
		}

		aqui: if(cheater == true){
			cout << "CHEATER\n";
		}
	}


	return 0;
}