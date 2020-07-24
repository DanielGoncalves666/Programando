#include<iostream>
using namespace std;

int main(){
	int mes, dia;
	int ano[] = {31,29,31,30,31,30,31,31,30,31,30,0};

	while(cin >> mes >> dia){
		if(mes == 12){
			if(dia == 24)
				cout << "E vespera de natal!" << endl;
			else if(dia == 25)
				cout << "E natal!" << endl;
			else if(dia > 25)
				cout << "Ja passou!" << endl;
			else{
				cout << "Faltam " << 25 - dia << " dias para o natal!" << endl;
			}
		}else{
			int total = 25;

			for(int i=11; i>mes-1; i--){
				total += ano[i];
			}

			total += ano[mes-1] - dia;

			cout << "Faltam " << total << " dias para o natal!" << endl;
		}
	}

	return 0;
}