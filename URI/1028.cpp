#include<iostream>
using namespace std;

int main(){
    int N,F1,F2;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> F1 >> F2;

        if(F1 == F2)
            cout << F1 << endl;
        else if(F1 < F2){
            int resto = F2%F1,aux;
            do{
                aux = F1%resto;
                F1 = resto;
                resto = aux;
            }while(aux != 0);
            cout << F1 << endl;
        }else{
            int resto = F1%F2,aux;
            do{
                aux = F2%resto;
                F2 = resto;
                resto = aux;
            }while(aux != 0);
            cout << F2 << endl;
        }
    }

    return 0;
}
