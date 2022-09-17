#include<iostream>
using namespace std;

    int x,y;

int main(){
    cin>>x>>y;
    if(x>=0 and x<=432){
        if(y>=0 and y<=468)
            cout<<"dentro\n";
        else
            cout<<"fora\n";
    }else
        cout<<"fora\n";

    return 0;
}
