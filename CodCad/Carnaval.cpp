#include<iostream>
using namespace std;

    double a,b,c,d,e,menor,maior,fim;

int main(){
    cin>>a;
    menor=a;
    maior=a;
    cin>>b;
    if(b<menor)
        menor=b;
    if(b>maior)
        maior=b;
    cin>>c;
    if(c<menor)
        menor=c;
    if(c>maior)
        maior=c;
    cin>>d;
    if(d<menor)
        menor=d;
    if(d>maior)
        maior=d;
    cin>>e;
    if(e<menor)
        menor=e;
    if(e>maior)
        maior=e;
    fim=a+b+c+d+e-maior-menor;
    cout.precision(1);
    cout.setf(ios::fixed);
    cout<<fim<<endl;
    return 0;
}
