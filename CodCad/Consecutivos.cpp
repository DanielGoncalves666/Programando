#include<iostream>
using namespace std;

    int i,N,V,qtd,seq,maior=0;

int main(){
    cin>>N;
    for(i=0;i<N;i++){
        cin>>V;
        if(i==0){
            seq=V;
            qtd=1;
        }else if(V==seq)
            qtd++;
        else{
            seq=V;
            if(qtd>=maior)
                maior=qtd;
            qtd=1;
        }
    }
    if(qtd>=maior)
        maior=qtd;
    cout<<maior<<endl;

    return 0;
}
