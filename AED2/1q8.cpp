#include <iostream>
using namespace std;
int main(int argc, char **argv)
{
	int v[4][5], x[5][2], p[4][2], y=0;
	for ( int i=0; i<4; i++){
		for ( int j=0; j<5; j++){
			cin>>v[i][j];
		}
	}
	for ( int i=0; i<5; i++){
		for ( int j=0; j<2; j++){
			cin>>x[i][j];
		}
	}
	for ( int i=0; i<4; i++){
		for ( int j=0; j<2; j++){
			for ( int l=0; l<5; l++){
				y= y+(v[i][l]*x[l][j]);
			}
			p[i][j]=y;
			y=0;
		}
	}
	for ( int i=0; i<4; i++){
		for ( int j=0; j<2; j++){
			cout<<p[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

