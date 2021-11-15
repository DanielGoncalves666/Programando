#include<iostream>
#include<string>
using namespace std;

int main(){
	string str, hora, minuto;
	int horas, minutos;

	while(cin >> str){
		size_t num = 3;
		horas = stoi(str,&num,10);
		str = str.substr(3,string::npos);
		minutos = stoi(str,NULL,10);

		for(int i=0; i<4; i++){
			if(horas % 2 == 1)
				hora.insert(0,"o");
			else{
				hora.insert(0," ");
			}
			horas /= 2;
		}

		for(int i=0; i<6; i++){
			if(minutos % 2 == 1){
				minuto.insert(0,"o");
			}else{
				minuto.insert(0," ");
			}
			minutos /= 2;
		}

		cout << " ____________________________________________" << endl;
		cout << "|                                            |" << endl;
		cout << "|    ____________________________________    |_" << endl;
		cout << "|   |                                    |   |_)" << endl;
		cout << "|   |   8         4         2         1  |   |" << endl;
		cout << "|   |                                    |   |" << endl;
		cout << "|   |   " << hora[0] << "         " << hora[1] << "         " << hora[2] << "         " << hora[3] << "  |   |" << endl;
		cout << "|   |                                    |   |" << endl;
		cout << "|   |                                    |   |" << endl;
		cout << "|   |   " << minuto[0] << "     " << minuto[1] << "     " << minuto[2] << "     " << minuto[3] << "     " << minuto[4] << "     " << minuto[5] << "  |   |" << endl;
		cout << "|   |                                    |   |" << endl;
		cout << "|   |   32    16    8     4     2     1  |   |_" << endl;
		cout << "|   |____________________________________|   |_)" << endl;
		cout << "|                                            |" << endl;
		cout << "|____________________________________________|" << endl;
		cout << endl;


		hora.clear();
		minuto.clear();
	}

	return 0;
}