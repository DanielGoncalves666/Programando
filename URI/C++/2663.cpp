#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool funcao(int i, int j){
	return i > j;
}

int main(){
	int N,K,total,num;

	cin >> N >> K;
	vector<int> vet;

	for(int i=0; i<N; i++){
		cin >> num;
		vet.push_back(num);
	}

	sort(vet.begin(),vet.end(),funcao);

	total = K;
	if(N == K){
		cout << N << endl;
	}else{
		for(int i = K;i<vet.size();i++){
			if(vet[i] == vet[i-1])
				total++;
			else
				break;
		}
		cout << total << endl;
	}


	return 0;
}