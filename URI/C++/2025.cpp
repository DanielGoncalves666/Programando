#include<iostream>
#include<cstring>
using namespace std;

int main(){
	int N;
	string str;

	cin >> N;
	getchar();

	for(int i=0; i<N; i++){
		getline(cin,str);

		int position = -1;//começa com -1 para quando for somar der 0
		do{
			int aux = str.find("oulupukk",position+1);

			if(aux != string::npos && aux > 0){//se for 0 pode ocorrer Runtime Error pelo primeiro termo do prox IF
				if(str[aux-1] != ' ' && str[aux+8] != ' ' && str[aux+8] != '.'){
					str[aux-1] = 'J';
					str[aux+8] = 'i';
				}
			}

			position = aux;
		}while(position != string::npos);

		cout << str << endl;
	}


	return 0;
}