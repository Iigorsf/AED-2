#include <iostream>
using namespace std; 

int main()
{
	int v[9];
	for( int i=0; i<9; i++){
		cin>>v[i];
	}
	for( int i=0; i<9; i++){
		if( v[i]==2 or v[i]==3 or v[i]==5 or v[i]==7){
			cout<<v[i]<<" "<<i<<endl;
		}
		else if( v[i]%2!=0 and v[i]%3!=0 and v[i]%5!=0 and v[i]%7!=0){
			cout<<v[i]<<" "<<i<<endl;
		}
	}
	return 0;
}

