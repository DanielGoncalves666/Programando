#include<iostream>
using namespace std;

int C,B,P,Cr,Br,Pr,nao = 0;

int main(){
    cin >> C >> B >> P;
    cin >> Cr >> Br >>Pr;

    if(C < Cr)
        nao += Cr - C;
    if(B < Br)
        nao += Br - B;
    if(P < Pr)
        nao += Pr - P;

    cout << nao << endl;

    return 0;
}
