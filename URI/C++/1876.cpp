#include<iostream>
using namespace std;

int main(){
	string str;

	while(getline(cin,str)){
		
		int h=0, qtd = 0,maior;
		for(int i=0;i<str.size();i++){
			if(str[i] == 'o'){
				qtd++;
				continue;
			}
			
			if(str[i] == 'x'){
				if(h == 0){
					maior = qtd;
				}else{
					qtd /= 2;
					if(maior < qtd)
						maior = qtd;
				}
				h++;
				qtd = 0;
			}
		}

		if(qtd > maior)
			cout << qtd << endl;
		else
			cout << maior << endl;
	}

	return 0;
}