#include <iostream>
using namespace std;

int resul(int v[][], int x, int y){
	if( x == 9 and y == 15){
		return 0;
	}
	else if( v[x][y] == '.'){
		v[x][y]= 'x';
		return resul( v, x, y+1);
	}
	else if( v[x][y] == '#'){
		if( ( v[x+1][y-1] != '#'){
			return resul( v, x+1, y-1);
		}
		else{
			return resul( v, 
	}
int main(int argc, char **argv)
{
	int v[10][15];
	for( int i=0; i<10; i++){
		for( int j=0; j<15; j++){
			cin>>v[i][j];
		}
	}
	resul( v, 0, 0);
	for( int i=0; i<10; i++){
		for( int j=0; j<15; j++){
			cout<<v[i][j];
		}
		cout<<endl;
	}
	
	return 0;
}

