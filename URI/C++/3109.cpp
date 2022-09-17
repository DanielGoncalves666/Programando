#include<iostream>
using namespace std;

int main(){
    int N,Q,E,A,B,qtd;
    cin >> N;
    int vet[N];
    for(int i=0; i<N; i++){
        vet[i] = i;
    }

    cin >> Q;
    for(int i=0; i<Q; i++){
        cin >> E;
        if(E == 1){
            cin >> A >> B;
            int aux = vet[A-1];
            vet[A-1] = vet[B-1];
            vet[B-1] = aux;
        }
        if(E == 2){
            cin >> A;
            qtd = 0;
            int aux = A;
            while(1){
                if(vet[aux-1] == A-1){
                    cout << qtd << endl;
                    break;
                }else{
                    aux = vet[aux-1] + 1;
                    qtd++;
                }
            }

        }
    }
    return 0;
}
