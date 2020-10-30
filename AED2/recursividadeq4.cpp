#include <iostream>
using namespace std;

int resul ( int n)
{
	int total=0;
	if( n<1){
		return total;
	}
	else{
		return total+1 + resul(n/10);
	}
		
}
int main(int argc, char **argv)
{
	int n;
	cin>>n;
	cout<<resul( n );
	
	return 0;
}

