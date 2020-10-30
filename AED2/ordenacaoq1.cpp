#include <iostream>
using namespace std;

void merge ( int v[], int inicio, int meio, int fim){
	int i=inicio;
	int j=meio+1;
	int tam= fim-inicio+1;
	int aux[tam];
	for( int x=0; x<tam; x++){
		if( i<=meio and j<=fim){
			if( v[i]<=v[j]){
				aux[x]=v[i];
				i++;
			}
			else{
				aux[x]=v[j];
				j++;
			}
		}
		else if( i>meio){
			aux[x]=v[j];
			j++;
		}
		else{
			aux[x]=v[i];
			i++;
		}
	}
	for( int x=0; x<tam; x++){
		v[inicio+x]=aux[x];
	}
}

void merget( int v[], int inicio, int fim){
	int meio;
	if( inicio < fim){
		meio =(inicio+fim)/2;
		merget( v, inicio, meio);
		merget(v, meio+1,fim);
		merge( v, inicio, meio, fim);
	}
}
				

int main(int argc, char **argv)
{
	int n;
	cin>>n;
	int v[n];
	for( int i=0; i<n; i++){
		cin>>v[i];
	}
	merget( v, 0, n);
	for( int i=0; i<n; i++){
		cout<<v[i]<<" ";
	}
	return 0;
}

