#include<iostream>
using namespace std;

int i,N,X,Y,h,soma;

int main(){
    cin>>N;
    for(i=0;i<N;i++){
        soma=0;
        cin>>X>>Y;
        if(X<Y){
            for(h=X+1;h<Y;h++){
                if(h%2==1)
                    soma+=h;
            }
        }
        else if(X>Y){
            for(h=X-1;h>Y;h--){
                if(h%2==1)
                    soma+=h;
            }
        }
        cout<<soma<<endl;
    }
    return 0;
}
