#include<iostream>
#include<cstring>
using namespace std;

int main(){
	int N;
	string S, I, linha, buffer;
	cin >> N;
	getline(cin,buffer);//eliminar quebra de linha

	for(int i=0; i<N; i++){
		getline(cin,S);
		getline(cin,linha);
		getline(cin,I);

		int position = 0;
		for(;;){
			int aux = linha.find(' ',position);
			if(aux == string::npos)
				break;

			linha.erase(aux,1);

			position = aux;
		}

		int *grupo = (int *) calloc(3,sizeof(int));

		if(S[0] == '*')
			grupo[0]++;
		
		if(I[0] == '*')
			grupo[0]++;

		if(linha[0] == '*')
			grupo[1]++;
		
		if(linha[1] == '*')
			grupo[2]++;

		if(linha[2] == '*')
			grupo[1]++;

		if(linha[3] == '*')
			grupo[2]++;

		int final = 1, nao = 0;
		int permutacoes = 0;//permotacoes pois posso variar os pares de posicao

		if(grupo[0] > 0){
			final *= grupo[0];
			if(grupo[0] == 2)
				permutacoes++;
		}else
			nao++;

		if(grupo[1] > 0){
			final *= grupo[1];
			if(grupo[1] == 2)
				permutacoes++;
		}else
			nao++;
		
		if(grupo[2] > 0){
			final *= grupo[2];
			if(grupo[2] == 2)
				permutacoes++;
		}else
			nao++;

		if(nao == 3)//se nenhum par estiver totalmente apagado
			final = 0;	

		if(permutacoes == 2)
			final *= (permutacoes - 1)*2;// vezes 2 pois dentro de um par eu posso variar os dois numeros

		if(permutacoes == 3)
			final *= (permutacoes)*2;


		cout << final << endl;

	}

	return 0;
}