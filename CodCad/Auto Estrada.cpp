#include<iostream>
using namespace std;

    int C,qtd=0,i;
    char letra;

int main(){
    cin>>C;
    for(i=0;i<C;i++){
        cin>>letra;
        if(letra=='P')
            qtd+=2;
        if(letra=='C')
            qtd+=2;
        if(letra=='A')
            qtd+=1;
        if(letra=='D')
            qtd+=0;
    }
    cout<<qtd<<endl;


    return 0;
}
