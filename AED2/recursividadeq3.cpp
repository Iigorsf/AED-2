#include <iostream>
using namespace std;
int resul( int v[], int n , int i)
{
	if( n==i ){
		return v[n];
	}
	else if( v[n]<v[i]){
		return resul( v, n, i+1 );
	}
	else{
		return resul( v, n-1, i);
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
	cout<<resul( v , n-1 , 0);
	return 0;
}

