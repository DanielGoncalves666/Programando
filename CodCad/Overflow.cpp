#include<iostream>
using namespace std;

    int N,P,Q,resul;
    char C;

int main(){
    cin>>N>>P >>C >>Q;
    if(C=='+')
        resul=P+Q;
    if(C=='*')
        resul=P*Q;
    if(resul>N)
        cout<<"OVERFLOW\n";
    else
        cout<<"OK\n";

    return 0;
}
