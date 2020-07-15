#include<iostream>
#include<cstring>
using namespace std;

int main(){
	string num, str;
	int caso = 1;

	while(cin >> num){
		if(caso > 1)
			cout << endl;
		
		getchar();
		getline(cin,str);
		
		int F = 0, M = 0;
		int location = -1;
		do{
			int aux = str.find(num,location+1);

			if(aux != string::npos){
				if(str[aux + 3] == 'F')
					F++;
				else if(str[aux + 3] == 'M')
					M++;
			}

			location = aux;
		}while(location != string::npos);


		cout << "Caso " << caso << ":" << endl;
		cout << "Pares Iguais: " << M+F << endl;
		cout << "F: " << F << endl;
		cout << "M: " << M << endl;
		caso++;
	}


	return 0;
}