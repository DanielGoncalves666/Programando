#include<iostream>
using namespace std;

    int a,pon,x,y,i=0,v=0;

int main(){
    cin>>a>>pon;

    while(i<a){
        cin>>x>>y;
        if(x+y>=pon)
            v++;
        i++;
    }
    cout<<v<<endl;
    return 0;
}
