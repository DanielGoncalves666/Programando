#include<iostream>
using namespace std;

int main(){
	int time, horas, minutos;

	cin >> time;

	horas = time / 3600;
	time -= horas * 3600;

	minutos = time / 60;
	time -= minutos * 60;

	cout << horas << ":" << minutos << ":" << time << endl;

	return 0;
}