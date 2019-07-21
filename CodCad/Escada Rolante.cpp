#include<iostream>
using namespace std;

    int N,i,h,t,qtd=0;

int main(){
    cin>>N;
    for(i=0;i<N;i++){
        cin>>t;
        if(i==0){
            h=t;
            continue;
        }
        if(h+10<t)
            qtd+=10;
        else
            qtd+=t-h;
        h=t;
    }
    qtd+=10;
    cout<<qtd<<endl;



    return 0;
}
