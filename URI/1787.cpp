#include<iostream>
#include<cmath>
using namespace std;

bool verifica_potencia(int numero);

int main(){
	int N;

	while(true){
		cin >> N;

		if(N == 0)
			break;

		int maior, num, index;
		int pontos[3] = {0,0,0}, vet[3];
		for(int i=0; i<N; i++){
			for(int h=0; h<3; h++){
				cin >> vet[h];

				if(h == 0){
					maior = vet[0];
					index = 0;
				}else if(vet[h] > maior){
					maior = vet[h];
					index = h;
				}
			}

			if(verifica_potencia(vet[0])){
				pontos[0]++;
				if(index == 0)
					pontos[0]++;
			}

			if(verifica_potencia(vet[1])){
				pontos[1]++;
				if(index == 1)
					pontos[1]++;
			}

			if(verifica_potencia(vet[2])){
				pontos[2]++;
				if(index == 2)
					pontos[2]++;
			}
		}

		if(pontos[0] > pontos[1] && pontos[0] > pontos[2]){
			cout << "Uilton" << endl;
		}else if(pontos[1] > pontos[0] && pontos[1] > pontos[2]){
			cout << "Rita" << endl;
		}else if(pontos[2] > pontos[0] && pontos[2] > pontos[1]){
			cout << "Ingred" << endl;
		}else{
			cout << "URI" << endl;
		}
	}

	return 0;
}


//se o numero for potencia de dois, log2 deve retornar um numero inteiro
bool verifica_potencia(int numero){
	if(numero % 2 == 1 || numero % 10 == 0)//colocar numero % 10 == 0 eliminou o erro de time limit exceed
		return false;

	int logaritmo = log2(numero);
	
	if(numero == pow(2,logaritmo))
		return true;
	else
		return false;
}