#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const char key=5;
	string cesar( string palavra, char chave){
		char qtdade='Z'-'A'+1;
		for( unsigned i=0; i<palavra.size(); i++){
			palavra[i]=(palavra[i]+key-'A')%qtdade+'A';
		}
		return palavra;
	}
	char cesar(char c, char chave){
		char qtdade='Z'-'A'+1;
		return (c+key-'A')%qtdade+'A';
	}
	
int main(int argc, char **argv)
{
	string nomeArq;
	cin>>nomeArq;
	ifstream arqEntrada(nomeArq.c_str());
	ofstream arqSaida("cifrado.txt");
	char c;
	while (arqEntrada.get(c)){
		if((c>='A')and(c<='Z')){
			c=cesar(c,key);
			}
			arqSaida.put(c);
		}
		
	return 0;
}

