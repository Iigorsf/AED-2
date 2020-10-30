#include <iostream>
using namespace std;
int H( int x);

int resul( int x)
{	
	if( x ==0 ){
		return 1;
	}
	else if( x>0 and x%2==0){
		return 2*H(x) + resul(x-1);
	}
	else{
		 return 2*H(x) - resul(x-1);
	 }
 }
int H( int x){
	if( x==0){
		return 0;
	}
	else{
		return H(x-1) + resul(x-1);
	}
}
	 
int main(int argc, char **argv)
{
	int x;
	cin>>x;
	cout<<resul( x );
	return 0;
}

