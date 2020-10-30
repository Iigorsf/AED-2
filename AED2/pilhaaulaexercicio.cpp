#include <iostream>
#include <math.h>
using namespace std;

class noh{
	friend class pilha;
	
	private:
	char dado;
	noh *proximo;
	
	public:
	noh(char dad);
	
};

noh::noh(char d){
	
	dado= d;
	proximo=NULL;
	
}

class pilha{
	
	private:
	noh *topo;
	int tamanho;
	
	public:
	pilha();
	~pilha();
	void inserir(char a);
	char remove();
	bool vazio();
};

pilha::pilha(){
	topo = NULL;
	tamanho = 0;
}

pilha::~pilha(){
	noh *aux;
	
	while( topo == NULL){
		aux = topo;
		topo= aux->proximo;
		delete aux;
		tamanho--;
	}
	
}
void pilha::inserir( char a){
	noh *novo = new noh(a);
	if( topo == NULL){
		topo = novo;
	}
	else{
		novo->proximo= topo;
		topo = novo;
	}
	tamanho++;
}

char pilha::remove(){
	char r;
	noh *aux;
	
	aux= topo;
	r = aux->dado;
	 topo=aux->proximo;
	delete aux;
	tamanho--;
	return r;
}

bool pilha::vazio(){
	if( topo == NULL){
		return true;
	}
	else{
		return false;
	}
}

int main(int argc, char **argv)
{
	pilha minhapilha;
	
	char a;
	
	cin>>a;
	while( a!='s'){
		minhapilha.inserir(a);
		cin>>a;	
	}
	
//	int pilha::resul(){
	
	int resultado=0;
	int trans=0;
	pilha operadores;
	
	char use;
	
	while( !minhapilha.vazio()){
		use= minhapilha.remove();
		if( (use == '+') or (use == '-') or (use == '*') or (use == '^') or (use == '/') or (use == '%' )){
			operadores.inserir(use);
		}
		else{
			trans=  (int)use;
			if( resultado == 0){
				resultado = trans;
			}
			else{
				char intermed;
				intermed = operadores.remove();
				if( intermed  == '+'){
					resultado= resultado + trans;
					}
					else if( intermed == '-'){
					resultado= resultado - trans;
					}
					else if( intermed == '*'){
					resultado= resultado * trans;
					}
					else if( intermed == '/'){
					resultado= resultado / trans;
					}
					else if( intermed == '%'){
					resultado= resultado % trans;
					}
					else if( intermed == '^'){
					resultado= pow(trans,resultado);
					}
					
			}
		}
	}
 
	cout<<resultado;
	
	return 0;
}

