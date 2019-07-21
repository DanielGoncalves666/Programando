#include<iostream>
using namespace std;

    int d,n,i=1,qtd=0;

int main(){
    cin>>d;
    while(i<=d){
        cin>>n;
        qtd+=n;
        if(qtd>=1000000)
            break;
        i++;
    }
    cout<<i<<endl;
    return 0;
}
