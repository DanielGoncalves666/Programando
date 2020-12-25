#include<iostream>
using namespace std;

int main(){
	double a,b,c,d,e,media;

	cin >> a >> b >> c >> d;
	media = (a*2 + b*3 + c*4 + d*1)/10;

	cout.precision(1);
	cout.setf(ios::fixed);
	cout << "Media: " << media << endl;

	if(media >= 7.0){
		cout << "Aluno aprovado." << endl;
	}else if(media < 5.0){
		cout << "Aluno reprovado." << endl;
	}else{
		cout << "Aluno em exame." << endl;
		cin >> e;

		cout << "Nota do exame: " << e << endl;
		media = (media + e)/2;

		if(media >= 5.0){
			cout << "Aluno aprovado." << endl;
		}else{
			cout << "Aluno reprovado." << endl;
		}

		cout << "Media final: " << media << endl; 
	}


	return 0;
}