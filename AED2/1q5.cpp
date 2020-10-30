#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
	int v[8], aux=0, j=0;
	for( int i=0; i<8; i++){
		cin>>v[i];
	}
		for (int i=1; i<8; i++){
			for( int x=0; x<i; x++){
		 cout<<v[x]<<" ";
	 }
	 cout<<endl;
	 aux = v[i];
	 j = i-1;
	 while (j >= 0 and aux < v[j]){
		 v[j+1] = v[j];
		 j--;
		 }
		 v[j+1] = aux;
	}
	for( int i=0; i<8; i++){
		 cout<<v[i]<<" ";
	 }
	return 0;
}

