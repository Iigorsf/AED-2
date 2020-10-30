#include <iostream>
using namespace std;
int main(int argc, char **argv)
{
	int v[20];
	float x1=0, x2=0, x3=0, x4=0, x5=0 , x6=0;
	for( int i=0; i<20; i++){
		cin>>v[i];
	}
	for( int i=0; i<20; i++){
		if( v[i]==1){
			x1++;
			}
			else if( v[i]==2){
			x2++;
			}
			else if( v[i]==3){
			x3++;
			}
			else if( v[i]==4){
			x4++;
			}
			else if( v[i]==5){
			x5++;
			}
			else if( v[i]==6){
			x6++;
			}
	}
		cout<<"1: "<<x1/20<<endl;
		cout<<"2: "<<x2/20<<endl;
		cout<<"3: "<<x3/20<<endl;
		cout<<"4: "<<x4/20<<endl;
		cout<<"5: "<<x5/20<<endl;
		cout<<"6: "<<x6/20<<endl;
	return 0;
}

