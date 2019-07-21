#include<iostream>
#include<cmath>
using namespace std;

    int N,i;
    double a;

int main(){
    cin>>N;
    for(i=0;i<N;i++){
        cin>>a;
        cout.precision(4);
        cout.setf(ios::fixed);
        cout<<sqrt(a)<<endl;
    }
    return 0;
}
