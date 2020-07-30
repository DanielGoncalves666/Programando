#include<iostream>
using namespace std;

int main(){
	int N,D,soma,num;
	string str;
	bool impresso;

	while(cin >> N >> D){
		impresso = false;
		for(int i=0; i<D; i++){
			cin >> str;

			soma = 0;
			for(int h=0; h<N; h++){
				cin >> num;
				soma += num;
			}

			if(soma == N && !impresso){
				impresso = true;
				cout << str << endl;
			}
		}

		if(!impresso){
			cout << "Pizza antes de FdI" << endl;
		}
	}


	return 0;
}