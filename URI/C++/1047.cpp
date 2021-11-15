#include<iostream>
using namespace std;

int main(){
	int hora_i, min_i, hora_f, min_f, hora_total = 0, min_total = 0;

	cin >> hora_i >> min_i >> hora_f >> min_f;

	if(hora_i == hora_f){
		if(min_i == min_f)
			hora_total = 24;
		else if(min_i < min_f){
			min_total = min_f - min_i;
		}else{
			hora_total = 23;
			min_total = (60 - min_i) + min_f;
		}
	}else if(hora_i < hora_f){
		hora_total = hora_f - (hora_i + 1);//pode ser que n haja hora completa, isso é compensando nos minutos
		min_total = (60 - min_i) + min_f;		
	}else{
		hora_total = (24 - (hora_i + 1)) + hora_f;//a mesma coisa que antes
		min_total = (60 - min_i) + min_f;
	}

	if(min_total > 60){
		min_total -= 60;
		hora_total++;
	}

	cout << "O JOGO DUROU " << hora_total << " HORA(S) E " << min_total << " MINUTO(S)\n";

	return 0;
}