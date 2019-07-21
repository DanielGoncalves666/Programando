#include<iostream>
using namespace std;

    double a,b,media;

int main(){
    cin>>a>>b;
    media=(a+b)/2.0;
    if(media>=7.0)
        cout<<"Aprovado\n";
    else if(media<7 and media>=4)
        cout<<"Recuperacao\n";
    else
        cout<<"Reprovado\n";

    return 0;
}
