#include<iostream>
using namespace std;

int B,N,D,C,V,i,qtd;

int main(){

    for(;;){
        qtd=0;
        cin>>B>>N;
        if(B==0 && N==0)
            break;
        int vet[B],vet2[B];

        for(i=0;i<B;i++){
            cin>>vet[i];
            vet2[i]=0;
        }

        for(i=0;i<N;i++){
            cin>>D>>C>>V;
            vet2[D-1]+=V;
            vet[C-1]+=V;
        }
        for(i=0;i<B;i++){
            if(vet[i]>=vet2[i])
                qtd++;
        }
        if(qtd==B)
            cout<<"S\n";
        else
            cout<<"N\n";
    }


    return 0;
}
