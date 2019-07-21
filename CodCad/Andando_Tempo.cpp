#include<iostream>
using namespace std;

    int a,b,c;

int main(){
    cin>>a>>b>>c;
    if(a==b || a==c || b==c)
        cout<<"S\n";
    else if(a+b==c || a+c==b || b+c==a)
        cout<<"S\n";
    else
        cout<<"N\n";

    return 0;
}
