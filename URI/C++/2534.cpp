#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool funcao(int i, int j){
	return i > j;
}

int main(){
	int N,Q,num;
	vector<int> vet;

	while(cin >> N >> Q){
		for(int i=0; i<N; i++){
			cin >> num;
			vet.push_back(num);
		}

		sort(vet.begin(),vet.end(),funcao);

		for(int i=0; i<Q; i++){
			cin >> num;
			cout << vet[num-1] << endl;
		}
		vet.clear();
	}

	return 0;
}