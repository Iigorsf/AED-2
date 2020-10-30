#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
	int n, m, posx, posy;
	bool c=false;
	cin>>n;
	int x[n], y[n];
	for( int i=0; i<n; i++){
		cin>>x[i];
	}
	for( int i=0; i<n; i++){
		cin>>y[i];
	}
	cin>>m;
	for( int i=0; i<n; i++){
		if( x[i]==m and c==false){
			posx=i;
			}
			for( int j=posx; j<n; j++){
				if( y[j]==m and c==false){
					posy=j;
					c=true;
			}
		}
	}
	for( int i=posx; i<posy+1; i++){
		cout<<x[i]<<endl;
	}
	for( int i=posx; i<posy+1; i++){
		cout<<y[i]<<endl;
	}
		
	return 0;
}

