#include<iostream>
#include<cstring>
using namespace std;

int main(){
	string num, cutoff;

	while(cin >> num){
		cin >> cutoff;
		
		int ponto_num = num.find('.');
		int ponto_cutoff = cutoff.find('.');
		int aux = 0;

		if(ponto_num == string::npos){
			cout << num << endl;//se não houver ponto, logo sem parte fracionária
			continue;
		}

		if(num.back() == '.'){
			num.erase(ponto_num);//se caso não tiver nada depois do ponto
			cout << num << endl;
			continue;
		}

		int igual = 0;
		for(int i = ponto_num + 1, h = ponto_cutoff + 1, j=0;; i++, h++, j++){			
			if(num[i] > cutoff[h]){
				aux++;
				num.erase(ponto_num,string::npos);
				break;
			}else if(num[i] == cutoff[h]){
				igual++;

				if(igual == 4){
					aux++;
					num.erase(ponto_num,string::npos);
					break;
				}
			}else if(num[i] < cutoff[h]){
				num.erase(ponto_num,string::npos);
				break;
			}
		}

		if(num.empty()){
			cout << aux << endl;
		}else{
			int numero = stoi(num) + aux;
			cout << numero << endl;
		}
	}

	return 0;
}