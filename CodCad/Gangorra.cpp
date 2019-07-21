#include<iostream>
using namespace std;

    int p1,p2,c1,c2;

int main(){
    cin>>p1>>c1>>p2>>c2;
    if(p1*c1==p2*c2)
        cout<<"0\n";
    else if(p1*c1<p2*c2)
        cout<<"1\n";
    else
        cout<<"-1\n";

    return 0;
}
