#include<iostream>
#include<cstring>
using namespace std;

int main(){
	int N, qtd;
	string str;

	cin >> N;
	getchar();

	for(int i=0; i<N; i++){
		qtd = 0;
		cin >> str;

		if(strchr(str.c_str(),'Q') != NULL)
			qtd++;

		if(strchr(str.c_str(),'J') != NULL)
			qtd++;

		if(strchr(str.c_str(),'K') != NULL)
			qtd++;
		
		if(strchr(str.c_str(),'A') != NULL)
			qtd++;

		if(qtd == 4)
			cout << "Aaah muleke" << endl;
		else
			cout << "Ooo raca viu" << endl;
	}


	return 0;
}