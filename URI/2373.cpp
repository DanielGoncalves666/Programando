#include<iostream>
using namespace std;

int N, l, c, quebrados = 0;

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> l >> c;
        if(l > c)
            quebrados += c;
    }
    cout << quebrados << endl;

    return 0;
}
