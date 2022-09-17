#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
	int N,M,num;
	vector<int> vet;

	cin >> N;

	for(int i=0; i<N; i++){
		cin >> M;
		
		for(int h=0; h<M; h++){
			cin >> num;

			if(num % 2 == 1){
				vet.push_back(num);
			}
		}

		if(vet.empty()){
			cout << endl;
			continue;
		}

		sort(vet.begin(),vet.end());

		if(vet.size() == 1)
			cout << vet[0];
		else{
			for(int j=vet.size()-1,h=0;;j--,h++){
				if(j == h){
					cout << " " << vet[j];
					break;
				}

				if(h > j)
					break;

				if(h != 0)
					cout << " ";
				
				cout << vet[j] << " " << vet[h];
			}
		}

		cout << endl;
		vet.clear();
	}


	return 0;
}