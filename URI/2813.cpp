#include<iostream>
using namespace std;

int main(){
	int N;
	string manha, tarde;

	cin >> N;
	getline(cin,manha);

	int qtd_casa = 0, qtd_escr = 0, comprados_casa = 0, comprados_escr = 0;
	for(int i=0; i<N; i++){
		cin >> manha >> tarde;

		int um = manha.compare("chuva");
		int dois = tarde.compare("chuva");

		if(um == 0 && dois == 0){
			if(qtd_casa == 0){
				comprados_casa++;
				qtd_casa++;//ele vai e volta com o guarda chuva
			}
		}else if(um == 0 && dois != 0 ){
			qtd_escr++;//ele deixa o guarda chuva no trabalho
			if(qtd_casa == 0){
				comprados_casa++;
			}else{
				qtd_casa--;//pq ele deixou no trabalho
			}
		}else if(um != 0 && dois == 0){
			qtd_casa++;//ele deixa o guarda chuva em casa
			if(qtd_escr == 0){
				comprados_escr++;
			}else{
				qtd_escr--;//pq ele deixou em casa
			}
		}
	}
	cout << comprados_casa << " " << comprados_escr << endl;


	return 0;
}