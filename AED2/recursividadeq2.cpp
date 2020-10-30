#include <iostream>
using namespace std;

int res( int n){
	if( n==1 ){
		return 1;
	}
	else{
		return 2*res(n-1)+1;
	}
}
int main(int argc, char **argv)
{
	int n;
	cin>>n;
	cout<<res( n );
	return 0;
}

