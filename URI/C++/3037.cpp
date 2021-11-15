#include<iostream>
using namespace std;

int main(){
    int N, maria, joao, ponto, dist;

    cin >> N;
    for(int i=0; i<N; i++){
        maria = 0, joao = 0;
        for(int h=0;h<3;h++){
            cin >> ponto >> dist;
            joao += ponto*dist;
        }
        for(int h=0;h<3;h++){
            cin >> ponto >> dist;
            maria += ponto*dist;
        }
        if(maria > joao)
            cout << "MARIA\n";
        else
            cout << "JOAO\n";
//não em uma opção pra empate
    }

    return 0;
}
