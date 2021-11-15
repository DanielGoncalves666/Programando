#include<iostream>
using namespace std;

int X, Y, M, xi, yi;

int main(){
	while(cin >> X >> Y >> M){
		for(int i=0; i<M; i++){
			cin >> xi >> yi;
			if(xi <= X && yi <= Y)
				cout << "Sim\n";
			else if(xi <= Y && yi <=X)
				cout << "Sim\n";
			else
				cout << "Nao\n";
		}
	}
	
	return 0;
}
