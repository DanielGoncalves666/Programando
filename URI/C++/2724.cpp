#include<iostream>
#include<cctype>
using namespace std;

int main(){
	int N,T,U;
	string experimento;

	cin >> N;

	for(int i=0; i<N; i++){
		cin >> T;
		string str[T];

		if(i != 0)
			cout << endl;

		for(int h=0; h<T; h++){
			cin >> str[h];
		}
		cin >> U;

		for(int h=0; h<U; h++){
			cin >> experimento;

			for(int j=0; j<T; j++){
				size_t pos = 0;
				do{
					size_t aux = experimento.find(str[j],pos);

					if(aux == string::npos){//composto não encontrado
						break;
					}else{
						size_t index = aux + str[j].size();
						if(index + 1 > experimento.size()){//composto perigoso
							goto aqui;
						}else if(islower(experimento[index]) == 0 && isdigit(experimento[index]) == 0){
							goto aqui;
						}else{//n é um composto perigoso no fim da string, ou tem uma letra minuscula depois
							//ou a qtd esta errada
							pos = aux + 1;
						}
					}
				}while(true);
			}
			if(false){
				aqui:
				cout << "Abortar" << endl;
			}else{
				cout << "Prossiga" << endl;
			}
		}

	}

	return 0;
}