#include<iostream>
using namespace std;

int N,maior = 0;

int main(){
    for(;;){
        cin >> N;
        if(N == 0){
            cout << maior << endl;
            break;
        }
        if(maior < N)
            maior = N;
    }

    return 0;
}

