#include<iostream>
using namespace std;

int main(){
    int area,N,estrela,qtd = 0;
    cin >> area;
    cin >> N;

    for(int i=0; i<N; i++){
        cin >> estrela;
        if(estrela*area >= 40000000)
            qtd++;
    }
    cout << qtd << endl;

    return 0;
}
