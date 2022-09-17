#include<iostream>
#include<vector>
using namespace std;

int main(){
	int N,C,M,num;

	cin >> N >> C >> M;
	vector<int> carimbadas;

	for(int i=0; i<C; i++){
		cin >> num;
		carimbadas.push_back(num);
	}

	for(int i=0; i<M; i++){
		cin >> num;
		for(int h=0; h < carimbadas.size(); h++){
			if(num == carimbadas[h]){
				carimbadas.erase(carimbadas.begin()+h);
			}
		}
	}

	cout << carimbadas.size() << endl;

	return 0;
}