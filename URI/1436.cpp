#include<iostream>
using namespace std;

int main(){
    int N,T;
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> T;
        int vet[T];
        for(int h=0; h<T; h++){
            cin >> vet[h];
        }

        cout << "Case " << i << ": " << vet[((T+1)/2) - 1] << endl;
    }

    return 0;
}
