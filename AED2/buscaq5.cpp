#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
	int n;
	cin>>n;
	int v[n], b, s;
	for( int i=0; i<n; i++){
		cin>>v[i];
	}
	cin>>b>>s;
	int meio=0,fim=n-1, i=0;
	while( i<=fim){
		meio= (i+fim)/2;
		if( v[meio]== b){
			v[meio]= s;
			i=n;
		}
		else if( v[meio]< b){
			i=meio+1;
		}
		else if( v[meio]>b){
			fim=meio-1;
		}
	}
	for( int i=0; i<n; i++){
		cout<<v[i]<<" ";
	}
	return 0;
}

