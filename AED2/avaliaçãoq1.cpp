#include <iostream>
using namespace std;
double phi( int n){
	if( n ==1){
		return 1;
	}
	else if( n>1){
		return 1+(1/phi(n-1));
	}
	else{
		return 0;
	}
}
int main(int argc, char **argv)
{
	int n;
	cin>>n;
	cout<<phi( n);
	return 0;
}

