#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
	int v[10][10],v1[10][10],v2[10][10],v3[10][10],v4[10][10];
	for ( int i=0; i<10; i++){
		for ( int j=0; j<10; j++){
			cin>>v[i][j];
		}
	}
	for ( int i=0; i<10; i++){
		for ( int j=0; j<10; j++){
			v1[i][j]=v[i][j];
			v2[i][j]=v[i][j];
			v3[i][j]=v[i][j];
			v4[i][j]=v[i][j];
		}
	}
	for ( int i=1; i<2; i++){
			for ( int l=7; l<8; l++){
				for ( int m=0; m<10; m++){
					v1[i][m]=v[l][m];
					v1[l][m]=v[i][m];
				}
			}
		}
	cout<<"1."<<endl;
	for ( int i=0; i<10; i++){
		for ( int j=0; j<10; j++){
			cout<<v1[i][j]<<" ";
		}
		cout<<endl;
	}
	for ( int i=3; i<4; i++){
			for ( int l=9; l<10; l++){
				for ( int m=0; m<10; m++){
					v2[m][i]=v[m][l];
					v2[m][l]=v[m][i];
				}
			}
		}
	cout<<"2."<<endl;
	for ( int i=0; i<10; i++){
		for ( int j=0; j<10; j++){
			cout<<v2[i][j]<<" ";
		}
		cout<<endl;
	}
	int x=0;
	for ( int i=9; i>=0; i--){
			for ( int l=x; l<x+1; l++){
				for ( int m=x; m<x+1; m++){
					v3[l][m]=v[i][m];
					v3[i][m]=v[i][i];
				}
			}
			if( x<10){
				x++;
			}
		}
	cout<<"3."<<endl;
	for ( int i=0; i<10; i++){
		for ( int j=0; j<10; j++){
			cout<<v3[i][j]<<" ";
		}
		cout<<endl;
	}
	for ( int i=4; i<5; i++){
			for ( int l=9; l<10; l++){
				for ( int m=0; m<10; m++){
					v4[i][m]=v[m][l];
					v4[m][l]=v[i][m];
				}
			}
		}
	cout<<"4."<<endl;
	for ( int i=0; i<10; i++){
		for ( int j=0; j<10; j++){
			cout<<v4[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

