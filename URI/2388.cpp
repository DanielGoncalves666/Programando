#include<iostream>
using namespace std;

int main(){
    int N,T,V,total=0;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> T >> V;
        total += T*V;
    }
    cout << total << endl;

    return 0;
}
