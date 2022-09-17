#include<iostream>
using namespace std;

    int N,i,l,c,qtd=0;

int main(){
    cin>>N;
    for(i=0;i<N;i++){
        cin>>l>>c;
        if(l>c)
            qtd+=c;
    }
    cout<<qtd<<endl;

    return 0;
}
