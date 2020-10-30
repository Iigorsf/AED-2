#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char **argv)
{
	char nome[30];
	cin>>nome;
	ifstream arq(nome);
	char letra;
	ofstream arq2("cifrado.txt");
	while (arq>>letra){
		if(letra=='X'){
			letra='A';
		}
		else if(letra=='Y'){
			letra='B';
		}
		else if(letra=='Z'){
			letra='C';
		}
		else if((letra>='A')and(letra<'X')){
			letra+=3;
		}
		arq2<<letra;
	}
	return 0;
}

