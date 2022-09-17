#include<iostream>
using namespace std;

    int a,b,c;

int main(){
    cin>>a>>b>>c;
    if(a<b and a<c){
        cout<<"1\n";
        if(b<c)
            cout<<"2\n"<<"3\n";
        else
            cout<<"3\n"<<"2\n";
    }
    if(b<a and b<c){
        if(a<c)
            cout<<"2\n"<<"1\n"<<"3\n";
        else
            cout<<"2\n"<<"3\n"<<"1\n";
    }
    if(c<b and c<a){
        if(a<b)
            cout<<"3\n"<<"1\n"<<"2\n";
        else
            cout<<"3\n"<<"2\n"<<"1\n";
    }

    return 0;
}
