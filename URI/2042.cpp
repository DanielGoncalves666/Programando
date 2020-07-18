#include<iostream>
using namespace std;

int main(){
	int N;
	string str = "3", aux = "";

	while(cin >> N){
		for(int i=1; i<N; i++){
			char letra;
			int qtd = 0;
			for(int h=0; h<str.size(); h++){
				if(h == 0){
					letra = str[h];
					qtd++;
				}else if(str[h] == letra){
					qtd++;
				}else if(str[h] != letra){
					aux.append(1,(char) qtd + 48);
					aux.append(1,letra);
					letra = str[h];
					qtd = 1;
				}

				if(h + 1 == str.size()){
					aux.append(1,(char) qtd + 48);
					aux.append(1,letra);
					str = aux;
					aux.clear();
					break;
				}

			}
		}
		cout << str << endl;
		str = "3";
	}

	return 0;
}