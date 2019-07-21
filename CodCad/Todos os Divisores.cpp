#include<iostream>
using namespace std;

    int a,i=1;

int main(){
    cin>>a;

    while(i<=a){
        if(a%i==0)
            cout<<i<<" ";
        i++;
    }
    cout<<endl;


    return 0;
}
