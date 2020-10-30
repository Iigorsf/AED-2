#include <iostream>
using namespace std;
int main(int argc, char **argv)
{
	int v[5], v2[5], v3[10], aux=0, j=0;
	for( int i=0; i<5; i++){
		cin>>v[i];
	}
	for( int i=0; i<5; i++){
		cin>>v2[i];
	}
	for( int i=0; i<5; i++){
		v3[i]=v[i];
		v3[i+5]=v2[i];
	}
	for (int i=1; i<10; i++){
	 aux = v3[i];
	 j = i-1;
	 while (j >= 0 and aux < v3[j]){
		 v3[j+1] = v3[j];
		 j--;
		 }
		 v3[j+1] = aux; 
	}
	for( int i=0; i<10; i++){
		cout<<v3[i]<<" ";
	}
	return 0;
}

