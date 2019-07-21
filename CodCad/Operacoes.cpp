#include<iostream>
using namespace std;

    char letra;
    double a,b,resul;

int main(){
    cin>>letra;
    cin>>a>>b;
    if(letra=='M')
        resul=a*b;
    if(letra=='D')
        resul=a/b;

    cout.precision(2);
    cout.setf(ios::fixed);
    cout<<resul<<endl;

    return 0;
}
