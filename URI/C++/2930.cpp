#include<iostream>
using namespace std;

int main(){
    int E,D;
    cin >> E >> D;
    if(E > D)
        cout << "Eu odeio a professora!\n";
    else{
        if(E + 3 <= D)
            cout << "Muito bem! Apresenta antes do Natal!\n";
        else{
            cout << "Parece o trabalho do meu filho!\n";
            if(E + 2 < 24)
                cout << "TCC Apresentado!\n";
            else
                cout << "Fail! Entao eh nataaaaal!\n";
        }

    }

    return 0;
}
