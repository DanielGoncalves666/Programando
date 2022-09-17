#include<iostream>
using namespace std;

    int N,i,total=0,divi,k=0;

int main(){
    cin>>N;
    int vet[N];
    for(i=0;i<N;i++){
        cin>>vet[i];
        total+=vet[i];
    }
    divi=total/2;
    total=0;
    for(i=0;i<N;i++){
        total+=vet[i];
        k++;
        if(total==divi)
            break;
    }
    cout<<k<<endl;
    return 0;
}
