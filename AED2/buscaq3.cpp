#include <iostream>
using namespace std;

struct animal{
	int iden;
	string nome;
	string dono;
	int dia;
	int mes;
	int ano;
	
};
int main(int argc, char **argv)
{
	int n=0;
	animal pet[100];
	bool c= false;
	cin>>pet[n].iden;
	while( pet[n].iden != 0){
		cin>>pet[n].nome;
		cin>>pet[n].dono;
		cin>>pet[n].dia;
		cin>>pet[n].mes;
		cin>>pet[n].ano; 
		n++;
		cin>>pet[n].iden;
	}
	int x;
	cin>>x;
	int meio=0, i=0, fim=n;
	while ( i<=fim and c==false){
		meio= (i+fim)/2;
		if( pet[meio].iden == x){
			c= true;
			cout<<pet[meio].nome<<" "<<pet[meio].dia<<"/"<<pet[meio].mes<<"/"<<pet[meio].ano;
		}
		else if( pet[meio].iden < x ){
			i= meio+1;
		}
		else{
			fim= meio-1;
		}
	}
	if( c == false){
		cout<<"inexistente";
	}
		
	return 0;
}
