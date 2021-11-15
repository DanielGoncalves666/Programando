#include<iostream>
#include<string>
using namespace std;

int main(){
    int N;
    string str, one = "one", two = "two";
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> str;
        if(str.size() == 3){
            int um=0, dois=0;
            for(int i=0; i<3; i++){
                if(str[i] == one[i])
                    um++;

                if(str[i] == two[i])
                    dois++;
            }
            if(um > dois)
                cout << "1" << endl;
            else
                cout << "2" << endl;

        }else if(str.size() == 5){
            cout << "3" << endl;
        }
    }


    return 0;
}
