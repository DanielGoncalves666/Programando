#include<iostream>
using namespace std;

int main(){
    int N,valor;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> valor;
        if(valor > 8000)
            cout << "Mais de 8000!\n";
        else
            cout << "Inseto!\n";
    }

    return 0;
}
