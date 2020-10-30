#include <iostream>
using namespace std;

struct meme
{
	int num;
	string nome;
	string assunto;
	string site;
	
};

void entrada( meme v[], int n){
		for( int i=0; i<n; i++){
		cin>>v[i].num;
		cin>>v[i].nome;
		cin>>v[i].assunto;
		cin>>v[i].site;
	}
}

void ordena( meme v[], int n){
	int maior=0, maiorp=0;
	for( int i=0; i<n-1; i++){
		maior=v[i].num;
		maiorp=i;
		for( int j= i+1; j<n; j++){
			if( maior > v[j].num){
				maior= v[j].num;
				maiorp=j;
				}
		}
		meme aux = v[i];
		v[i] = v[maiorp];
		v[maiorp] = aux;
		
	}
}
	
void busca( meme v[], int n, string buscador)
{
	bool x=false;
	for( int i=0; i<n; i++){
		if( v[i].site == buscador){
			cout<<v[i].num<<" "<<v[i].nome<<" "<<v[i].assunto<<" "<<v[i].site<<endl;
			x=true;
		}
	}
	if( x==false){
		cout<<"NULL";
	}
}

int main(int argc, char **argv)
{
	int n;
	cin>>n;
	meme v[n];
	entrada ( v, n);
	ordena( v , n);
	string buscador;
	cin>>buscador;
	busca( v , n , buscador);
	
	return 0;
}

