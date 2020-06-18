#include<iostream>
using namespace std;

int main(){
    int N;
    cin >> N;

    for(int i=0; i<N; i++){
        int N,K;
        cin >> N >> K;

        if(N == K)
            cout << "1\n";
        else if(N < K)
            cout << N << endl;
        else{
            int extras = N / K;
            cout << extras + N%K << endl;
        }
    }

    return 0;
}
