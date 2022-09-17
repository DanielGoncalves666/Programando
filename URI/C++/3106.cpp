#include<iostream>
using namespace std;

int main(){
    int N,total=0,num;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> num;
        total += num/3;
    }
    cout << total * 3<< endl;

    return 0;
}

