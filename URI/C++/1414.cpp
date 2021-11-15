#include<iostream>
using namespace std;

int main(){
	int T, N;
	string nome;

	while(true){
		cin >> T >> N;

		if(T == 0)
			break;

		int vet[T], empates = 0, vitorias = 0;

		for(int i=0; i<T; i++){
			getline(cin,nome);//buffer
			cin >> nome;
			cin >> vet[i];

			if(vet[i] % 3 == 0)
				vitorias += vet[i] / 3;
			else{
				empates += vet[i] % 3;
				vitorias += vet[i] / 3;
			}
		}

		if(empates % 2 == 0){
			empates /= 2;//um ponto pra cada time
			if(N != empates + vitorias){
				do{
					vitorias -= 2;//eu tiro 6 pontos em vitorias
					empates += 3;//e distribui em 3 empates, cada time recebendo um ponto

				}while(N != empates + vitorias);
			}
		}else{
			vitorias -= 1;//tiro os 3 pontos de uma vitoria
			empates += 3;//e adiciono 3 PONTOS em empates
			empates /= 2;//um ponto pra cada time
			
			if(N != empates + vitorias){
				do{
					vitorias -= 2;//eu tiro 6 pontos em vitorias
					empates += 3;//e distribui em 3 empates, cada time recebendo um ponto

				}while(N != empates + vitorias);
			}
		}
		
		cout << empates << endl;
	}

	return 0;
}