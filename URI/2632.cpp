#include<iostream>
#include<cmath>
using namespace std;

int magia(string *str);
int determinar_raio(string *str, int nivel);

int main(){
	int N,w,h,x0,y0,n,cx,cy;
	string str;

	cin >> N;

	for(int i=0; i<N; i++){
		cin >> w >> h >> x0 >> y0;
		
		cin >> str;
		cin >> n >> cx >> cy;

		pair <int,int> x0y0 (x0,y0), x1y0 (x0+w,y0), x1y1 (x0+w,y0+h), x0y1 (x0,y0+h);
		/*
		x0y1	x1y1
		x0y0	x1y0
		*/

		int dano = magia(&str), raio = determinar_raio(&str,n);

		if(cx <= x1y1.first && cx >= x0y0.first && cy <= x1y1.second && cy >= x0y0.second){
			//o centro da circunferencia esta dentro do retangulo
			cout << dano << endl;
			continue;
		}

		if(cy > x0y0.second && cy < x1y1.second){//o centro esta na extensao horizontal do retangulo
			if((cx <= x1y1.first + raio && cx > x1y1.first) || (cx >= x0y0.first - raio && cx < x0y0.first)){
				//se a distancia das arestas verticais ate o centro da circunferencia for menor ou igual ao raio
				cout << dano << endl;
			}else{
				cout << "0" << endl;
			}
			continue;
		}

		if(cx > x0y0.first && cx < x1y1.first){// o centro esta na extensao vertical do retangulo
			if((cy <= x1y1.second + raio && cy > x1y1.second) || (cy >= x0y0.second - raio && cy < x0y0.second)){
				//se a distancia das arestas horizontais ate o centro da circunferencia for menor ou igual ao raio
				cout << dano << endl;
			}else{
				cout << "0" << endl;
			}
			continue;
		}

		if(sqrt(pow(cx - x0y0.first,2) + pow(cy - x0y0.second,2)) <= raio){
			//se a distancia entre o vertice inferior esquerdo e o centro da circunferencia for menor ou igual ao raio
			//o inimigo ser atingido. Isso valerá para todos os quatro
			cout << dano << endl;
			continue;
		}

		if(sqrt(pow(cx - x1y0.first,2) + pow(cy - x1y0.second,2)) <= raio){
			cout << dano << endl;
			continue;
		}

		if(sqrt(pow(cx - x0y1.first,2) + pow(cy - x0y1.second,2)) <= raio){
			cout << dano << endl;
			continue;
		}

		if(sqrt(pow(cx - x1y1.first,2) + pow(cy - x1y1.second,2)) <= raio){
			cout << dano << endl;
			continue;
		}

		cout << "0" << endl;
	}

	return 0;
}

int magia(string *str){
	if(str->compare("fire") == 0)
		return 200;
	else if(str->compare("water") == 0){
		return 300;
	}else if(str->compare("earth") == 0){
		return 400;
	}else if(str->compare("air") == 0){
		return 100;
	}
}

int determinar_raio(string *str, int nivel){
	int mat[4][3] = {{18,38,60},{20,30,50},{10,25,40},{25,55,70}} ;
	
	int index = (magia(str)/100) - 1;

	return mat[index][nivel-1];
}