#include<iostream>
using namespace std;

    int a,b,i,soma;

int main(){
    for(;;){
        soma=0;
        cin>>a>>b;
        if(a<=0 || b<=0)
            break;
        if(a<=b){
            for(i=a;i<=b;i++){
                cout<<i<<" ";
                soma+=i;
            }
            cout<<"Sum="<<soma<<endl;
        }else{
            for(i=b;i<=a;i++){
                cout<<i<<" ";
                soma+=i;
            }
            cout<<"Sum="<<soma<<endl;
        }
    }
    return 0;
}
