#include<iostream>
using namespace std;

    int n,s,h,i=0,menor,atual;

int main(){
    cin>>n>>s;
    while(i<n){
        cin>>h;
        if(i==0){
            atual=s+h;
            menor=atual;
        }else if(atual+h<menor){
            menor=atual+h;
            atual+=h;
        }else
            atual+=h;
        i++;
    }
    cout<<menor<<endl;
    return 0;
}
