#include<iostream>
using namespace std;

    int v1,e1,s1,v2,e2,s2;

int main(){
    cin>>v1>>e1>>s1>>v2>>e2>>s2;
    if(v1*3+e1>v2*3+e2)
        cout<<"C\n";
    else if(v1*3+e1<v2*3+e2)
        cout<<"F\n";
    else{
        if(s1>s2)
            cout<<"C\n";
        else if(s1<s2)
            cout<<"F\n";
        else
            cout<<"=\n";
    }

    return 0;
}
