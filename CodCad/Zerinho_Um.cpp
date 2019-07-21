#include<iostream>
using namespace std;

    int a,b,c;

int main(){
    cin>>a>>b>>c;
    if(a==b and b==c)
        cout<<"*\n";
    else if(a==b)
        cout<<"C\n";
    else if(a==c)
        cout<<"B\n";
    else if(b==c)
        cout<<"A\n";

    return 0;
}
