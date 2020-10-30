#include <iostream>
using namespace std;
 struct campeonato
 {
	 string nome;
	 string times;
	 int pontos[5];
	 int saques[5];
	 int bloq[5];
	 int spontos;
	 int ssaques;
	 int sbloq;
 };
 int som( int v[])
 {
	 int soma=0;
	for( int j=0; j<5; j++){
		soma+=v[j];
	}
		return soma;
 }
int main(int argc, char **argv)
{
	int n;
	cin>>n;
	campeonato v[n];
	for ( int i=0; i<n; i++){
		cin>>v[i].nome;
		cin>>v[i].times;
		for( int j=0; j<5; j++){
			cin>>v[i].pontos[j];
		}
		for( int j=0; j<5; j++){
			cin>>v[i].saques[j];
		}
		for( int j=0; j<5; j++){
			cin>>v[i].bloq[j];
		}
	}
	for ( int i=0; i<n; i++){
		v[i].spontos=som(v[i].pontos);
		v[i].ssaques=som(v[i].saques);
		v[i].sbloq=som(v[i].bloq);
	}
	int m=0, ml=0;
	m=v[0].spontos;
	for( int i=0; i<n; i++){
		if( m<v[i].spontos){
			m=v[i].spontos;
			ml=i;
		}
	}
	cout<<v[ml].nome<<endl;
	m=v[0].ssaques;
	for( int i=0; i<n; i++){
		if( m<v[i].ssaques){
			m=v[i].ssaques;
			ml=i;
		}
	}
	cout<<v[ml].nome<<endl;
	m=v[0].sbloq;
	for( int i=0; i<n; i++){
		if( m<v[i].sbloq){
			m=v[i].sbloq;
			ml=i;
		}
	}
	cout<<v[ml].nome<<endl;
	int tim=0, aux2=0;
	string v1[tim+1], aux=0;
	v1[0]=v[0].times;
	for ( int i=0; i<n; i++){
		if(v1[i]!=v[i].times){
			aux=v[i].times;
			for( int j=i; j>0; j--){
				if( v[i].times!=v[j].times){
					aux2++;
				}
			}
			if( aux2 == i-1){
				tim++;
				v1[tim-1]=aux;
			}
			aux2=0;
		}
	}
	for( int i=0; i<tim; i++){
		cout<<v1[i]<<endl;
	}
					
	return 0;
}
