#include<iostream>
using namespace std;

int N,i,X,h,soma;

int main(){
    cin>>N;
    for(i=0;i<N;i++){
        cin>>X;
        soma=0;
        for(h=1;h<=X/2;h++){
            if(X%h==0)
                soma+=h;
        }
        if(X==soma)
            cout<<X<<" eh perfeito"<<endl;
        else
            cout<<X<<" nao eh perfeito"<<endl;
    }
    return 0;
}
