#include<iostream>
using namespace std;

    int N,i,a,menor;

int main(){
    cin>>N;
    for(i=0;i<N;i++){
        cin>>a;
        if(i==0)
            menor=a;
        else if(menor>a)
            menor=a;
    }
    cout<<menor<<endl;

    return 0;
}
