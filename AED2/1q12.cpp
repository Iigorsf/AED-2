#include <iostream>
using namespace std;

struct atleta
{
	int cod;
	string nome;
	int ida;
	int pes;
	char sex;
	int dia=0;
	float dis=0;
	float temp=0;
};

int main(int argc, char **argv)
{
	int a;
	cin>>a;
	atleta atl[a];
	bool x=false;
	for( int i=0; i<a; i++){
		cin>>atl[i].cod;
		cin>>atl[i].nome;
		cin>>atl[i].ida;
		cin>>atl[i].pes;
		cin>>atl[i].sex;
		if( atl[i].sex =='M'){
			x=true;
		}
	}
	int n=0, y=0;
	cin>>n;
	while( n!=-1){
		cin>>y;
		atl[y-1].dia++;
		float dist;
		cin>>dist;
		atl[y-1].dis+=dist;
		float tempo;
		cin>>tempo;
		atl[y-1].temp+=tempo;
		cin>>n;
		}
	if( x==false){
		cout<<-1<<endl;
	}
	else{
		int velho=0, velhos=0;
		for( int i=0; i<a; i++){
			if( atl[i].sex == 'M'){
				velho=atl[i].ida;
				i=a;
			}
		}
		for( int i=0; i<a; i++){
			if( velho<atl[i].ida and atl[i].sex == 'M'){
			velho=atl[i].ida;
			velhos=i;
			}
		}
		cout<<atl[velhos].nome<<" "<<atl[velhos].dis<<endl;
	}
	int dia=0, dias=0;
	dia=atl[0].dia;
	for( int i=0; i<a; i++){
		if( dia<atl[i].dia){
			dia=atl[i].dia;
			dias=i;
		}
	}
	cout<<atl[dias].nome<<" "<<atl[dias].ida<<endl;
	float med=0;
	for( int i=0; i<a; i++){
		int divizor;
		if( atl[i].dia == 0){
			divizor=1;
		}
		else{
			divizor=atl[i].dia;
		}
		med= atl[i].temp/divizor;
		cout<<atl[i].nome<<" "<<med<<endl;
	}
	return 0;
}

