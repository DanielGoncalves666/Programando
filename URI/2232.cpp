#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int N, T,soma;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> T;
        soma = 0;
        for(int h=0; h<T; h++){
            soma += pow(2,h);
        }
        cout << soma << endl;
    }

    return 0;
}
