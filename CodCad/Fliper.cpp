#include<iostream>
using namespace std;

    int a,b;

int main(){
    cin>>a>>b;
    if(a==0)
        cout<<"C\n";
    if(a==1){
        if(b==0)
            cout<<"B\n";
        else
            cout<<"A\n";
    }
    return 0;
}
