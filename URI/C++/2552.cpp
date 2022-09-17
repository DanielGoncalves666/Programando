#include<iostream>
using namespace std;

int main(){
	int N,M;

	while(cin >> N >> M){
		int vet[N][M],result[N][M];

		for(int i=0;i<N;i++){
			for(int h=0; h<M; h++){
				result[i][h] = 0;
			}
		}

		for(int i=0; i<N; i++){
			for(int h=0; h<M; h++){
				cin >> vet[i][h];

				if(vet[i][h] == 1){
					if(i-1 >= 0){
						result[i-1][h]++;
					}

					if(i+1 < N){
						result[i+1][h]++;
					}

					if(h-1 >= 0){
						result[i][h-1]++;
					}

					if(h+1 < M){
						result[i][h+1]++;
					}
				}
			}
		}

		for(int i=0; i<N; i++){
			for(int h=0; h<M; h++){
				if(vet[i][h] == 1)
					cout << 9;
				else
					cout << result[i][h];
			}	
			cout << endl;
		}
	}

	return 0;
}