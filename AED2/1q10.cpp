#include <iostream>
using namespace std;
int main(int argc, char **argv)
{
	int x , y;
	cin>>x>>y;
	int v[x][y];
	for ( int i=0; i<x; i++){
		for ( int j=0; j<y; j++){
			cin>>v[i][j];
		}
	}
	for ( int i=0; i<y; i++){
		for ( int j=0; j<x; j++){
			cout<<v[j][i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

