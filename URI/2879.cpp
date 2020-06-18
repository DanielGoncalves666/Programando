#include<iostream>
using namespace std;

int main(){
    int N,total=0,carro;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> carro;
        if(carro == 2)
            total++;
        else if(carro == 3)
            total++;
    }
    cout << total << endl;

    return 0;
}
