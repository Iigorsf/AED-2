#include <iostream>
using namespace std;
int main(int argc, char **argv)
{
	int m, n, x=0;
	cin>>m>>n;
	float v[m], v1[n];
	bool l=true;
	for ( int i=0; i<m; i++){
		cin>>v[i];
	}
	for ( int i=0; i<n; i++){
		cin>>v1[i];
	}
	for ( int i=0; i<m; i++){
		for ( int j=0; j<n; j++){
			if( v[i]==v1[j]){
				cout<<v[i]<<" ";
				l=false;
			}
		}
	}
	if( l==true){
		cout<<-1;
	}
	cout<<endl;
	for ( int i=0; i<m; i++){
		cout<<v[i]<<" ";
	}
		for ( int i=0; i<n; i++){
		for ( int j=0; j<m; j++){
			if( v1[i]!=v[j]){
				x++;
			}
		}
		if( x==m){
			cout<<v1[i]<<" ";
		}
		x=0;
	}
	return 0;
}

