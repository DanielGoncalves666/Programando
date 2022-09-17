#include<iostream>
using namespace std;

int main(){
    int P1, C1, P2, C2;
    cin >> P1 >> C1 >> P2 >> C2;
    if(P1*C1 == P2*C2)
        cout << "0\n";
    else if(P1*C1 < P2*C2)
        cout << "1\n";
    else
        cout << "-1\n";

    return 0;
}
