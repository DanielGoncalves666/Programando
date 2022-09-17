#include<iostream>
using namespace std;

    int a,b,c,d;

int main(){

    cin>>a>>b>>c>>d;
    if(a*b<c*d)
        cout<<"Segundo"<<endl;
    if(a*b>c*d)
        cout<<"Primeiro"<<endl;
    if(a*b==c*d)
        cout<<"Empate"<<endl;

    return 0;
}
