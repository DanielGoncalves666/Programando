#include<iostream>
#include<string>
using namespace std;

int main(){
    int N,joao,jose,pagar;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> jose >> joao;

        if(jose == 0)
            pagar = joao + 1;
        else if(joao == 0 && jose>=1){
            joao = 1;
            if(jose - 1 == 0)
                pagar = joao + 1;
            else if()

        }else if(joao > 0 && jose > 0){

        }

    }

    return 0;
}
