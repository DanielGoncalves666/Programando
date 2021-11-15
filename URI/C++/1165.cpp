#include<iostream>
#include<cmath>
using namespace std;

int N,X,i,h,primo;

int main(){
    cin>>N;
    for(i=0;i<N;i++){
        cin>>X;
        primo=1;
        for(h=2;h<=sqrt(X);h++){
            if(X<=2)
                break;
            if(X%h==0)
                primo=0;
        }
        if(X<=1)
            primo=0;
        if(primo==0)
            cout<<X<<" nao eh primo"<<endl;
        else if(primo==1)
            cout<<X<<" eh primo"<<endl;
    }
    return 0;
}
