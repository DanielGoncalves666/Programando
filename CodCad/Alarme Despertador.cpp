#include<iostream>
using namespace std;

    int h1,m1,h2,m2,minu;

int main(){
    while(1){
        cin>>h1>>m1>>h2>>m2;
        if(h1==0 and h2==0 and m1==0 and m2==0)
            break;
        minu=60-m1+m2;
        if(h2==h1){
            if(m1<m2)
                cout<<minu-60<<endl;
            else
                cout<<minu+23*60<<endl;
        }else if(h2>h1)
            cout<<minu+(h2-h1-1)*60<<endl;
        else if(h2<h1)
            cout<<minu+(24-h1+h2-1)*60<<endl;
    }

    return 0;
}
