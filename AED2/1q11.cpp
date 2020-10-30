#include <iostream>
#include <cmath>
using namespace std;
struct Geo
{
	char tipo;
	float raio;
    float base;
    float altura;
	float lado1;
    float lado2;
    float lado3;
};
float per( float x, float y, float z)
{
	int a;
	a= (x+y+z)/2;
	return a;
}
int main(int argc, char **argv)
{
	Geo x[5];

	for( int i=0; i<5; i++){
		cin>>x[i].tipo;
		
		if( x[i].tipo == 'C'){
			cin>>x[i].raio;
		}
		
		else if( x[i].tipo == 'R'){
			cin>>x[i].base;
			cin>>x[i].altura;
		}
		else if( x[i].tipo == 'T'){
			cin>>x[i].lado1;
			cin>>x[i].lado2;
			cin>>x[i].lado3;
		}
	}
		for( int i=0; i<5; i++){
		if( x[i].tipo == 'C'){
			cout<<"Circulo "<<x[i].raio*( M_PI*2)<<" "<<(x[i].raio*x[i].raio)* M_PI<<endl;
		}
		else if( x[i].tipo == 'R'){
			cout<<"retangulo "<<(x[i].base*2)+(x[i].altura*2)<<" "<<x[i].base*x[i].altura<<endl;;
		}
		else if( x[i].tipo == 'T'){
			float a=per(x[i].lado1,x[i].lado2,x[i].lado3);
			cout<<"Triangulo "<<x[i].lado1+x[i].lado2+x[i].lado3<<" "<<sqrt(a*(a-x[i].lado1)*(a-x[i].lado2)*(a-x[i].lado3))<<endl;
		}
	}
	return 0;
}

