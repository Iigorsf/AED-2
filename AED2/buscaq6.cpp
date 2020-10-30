#include <iostream>
using namespace std;
int main(int argc, char **argv)
{
	string text;
	cin>>text;
	string palavra;
	cin>>palavra;
	int c=-1, tam, tam2;
	tam = text.size();
	tam2 = palavra.size();
	for(int i = 0; i <=(tam-tam2);i++){
		if(text[i]==palavra[0] and c==-1){
			c = i;
			for(int j =0; j < tam2; j++)
			{
				if(text[i+j] != palavra[j])
				{
					j = tam2;
					c = -1;
				}
			}
		}
	}
	cout<<c;
	return 0;
}
