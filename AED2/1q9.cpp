#include <iostream>
using namespace std;
int main(int argc, char **argv)
{
	int v[10][10], max=0, min=0, maxp=0, minp=0;
	for ( int i=0; i<10; i++){
		for ( int j=0; j<10; j++){
			cin>>v[i][j];
		}
	}
	max= v[0][0];
	for ( int i=0; i<10; i++){
		for ( int j=0; j<10; j++){
			if( v[i][j]>max){
				max=v[i][j];
				maxp=i;
			}
		}
	}
	min=v[maxp][0];
	for ( int i=0; i<10; i++){
		if( v[maxp][i]<min){
			min=v[maxp][i];
			minp=i;
		}
	}
	cout<<min<<endl<<maxp<<" "<<minp;
	return 0;
}

