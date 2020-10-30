#include <iostream>
using namespace std;
int main(int argc, char **argv)
{
	int v[10];
	for( int i=0; i<10; i++){
		cin>>v[i];
	}
	for( int i=0; i<10; i++){
		if( v[i]>0){
		cout<<v[i]<<" ";
	}
	}
	return 0;
}

