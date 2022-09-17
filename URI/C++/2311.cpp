#include<iostream>
#include<vector>

int main(){
	int N;
	double multiplier, num;
	std::string nome;

	std::cin >> N;

	for(int i=0; i<N; i++){
		std::getline(std::cin,nome);//elimina o buffer
		std::getline(std::cin,nome);

		std::cin >> multiplier;
		double menor, maior, total = 0.0;
		for(int h=0; h<7; h++){
			std::cin >> num;
			total += num;

			if(h == 0){
				menor = num;
				maior = num;
			}
			
			if(num > maior){
				maior = num;
			}

			if(num < menor){
				menor = num;
			}
		}
		total -= menor + maior;

		std::cout.precision(2);
		std::cout.setf(std::ios::fixed);
		std::cout << nome << " " << total*multiplier << std::endl;
	}


	return 0;
}