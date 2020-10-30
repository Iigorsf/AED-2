#include <iostream>
using namespace std;

class noh{
	friend class fila;
	private:
	int iden;
	int dado;
	noh* proximo;
	public:
	noh ( int dado, int in);
};

noh::noh ( int dad, int i){
	iden= i;
	dado= dad;
	proximo= NULL;
}

class fila{
	private:
	noh *inicio;
	noh *fim;
	int tamanho;
	int capacidade;
	public:
	fila();
	~fila();
	void insere( int dado, int i);
	void remove();
	void imprimir();
	void capacidad( int num);
};

fila::fila(){
	inicio = NULL;
	fim = NULL;
	tamanho= 0;
}

fila::~fila(){
	noh *aux;
	aux= inicio;
	while(  inicio != NULL){
		noh *del;
		del = aux;
		aux = aux->proximo;
		delete del;
	}
}

void fila::capacidad(int num){
	capacidade = num;
}

void fila::insere( int dado, int i){
	noh *aux= new noh( dado, i);
	
	if( inicio == NULL ){
		inicio = aux;
		fim = aux;
		tamanho++;
	}
	else {
		aux->proximo = fim;
		fim = aux;
		tamanho++;
	}
}

void fila::remove(){
	noh *aux;
	aux= inicio;
	aux->iden= ' ' ;
	tamanho--;
}

void fila::imprimir(){
	cout<<"tamanho="<<tamanho<<" capacidade="<<capacidade;
	cout<<" inicio="<<inicio->iden<<" fim="<<fim->iden;
	noh *aux;
	aux= inicio;
	while( aux != NULL){
		
	}
}

int main(int argc, char **argv)
{
	fila circular;
	int n, dado, i=0;
	cin>>n;
	circular.capacidad( n);
	char opc;
	cin>>opc;
	while(opc == 't'){
		if( opc == 'e'){
			cin>>dado;
			circular.insere( dado, i);
			i++;
		}
		else if( opc == 'd'){
			circular.remove();
		}
		else if( opc == 'i'){
			circular.imprimir();
		}
		cin>>opc;
	}
	
	return 0;
}

