#include<iostream>
using namespace std;

    int n,i=0,maior;

int main(){
    while(1){
        cin>>n;
        if(n==0)
            break;
        if(i==0){
            maior=n;
            i++;
        }else if(maior<n)
            maior=n;
    }
    cout<<maior<<endl;

    return 0;
}
