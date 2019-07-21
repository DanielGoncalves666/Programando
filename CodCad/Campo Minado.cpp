#include<iostream>
using namespace std;

    int N,i,a;

int main(){
    cin>>N;
    int vet[N];
    for(i=0;i<N;i++){
        cin>>vet[i];
    }
    for(i=0;i<N;i++){
        a=0;
        if(i==0){
            if(N>1)
                a=vet[i]+vet[i+1];
            else
                a=vet[i];
        }else if(i==N-1)
            a=vet[N-1]+vet[N-2];
        else
            a=vet[i-1]+vet[i]+vet[i+1];

        cout<<a<<endl;
    }

    return 0;
}
