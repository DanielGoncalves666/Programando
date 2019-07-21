#include<iostream>
using namespace std;

    int p,n,i,f,pont;

int main(){
    cin>>p>>n;
    for(i=0;i<n;i++){
        cin>>f;
        if(i==0)
            pont=p+f;
        else{
            pont+=f;
            if(pont<0)
                pont=0;
            if(pont>100)
                pont=100;
        }
    }
    cout<<pont<<endl;

    return 0;
}
