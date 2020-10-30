#include <iostream>
using namespace std;

class noh{
	friend class fila;
	private:
	int dado;
	noh* proximo;
	public:
	noh ( int dado);
};

noh::noh ( int dad){
	dado= dad;
	proximo= NULL;
}

class fila{
	private:
	noh* inicio;
	noh* fim;
	int tamanho = 0;
	public:
	fila();
	~fila();
	void inserir(int dado);
	void imprimi();
	int retorno( int exe);
	void insere( int a, int local);
};

fila::fila(){
	inicio = NULL;
	fim = NULL;
	tamanho = 0;
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

void fila::inserir(int dado){
	noh *aux= new noh( dado);
	
	if( inicio == NULL ){
		inicio = aux;
		fim = aux;
		tamanho++;
	}
	else{
		aux->proximo = fim;
		fim = aux;
		tamanho++;
	}
}
	
void fila:: imprimi(){
	noh *aux;
	aux = inicio;
	while( aux != NULL){
		cout<<aux<<" ";
		aux= aux->proximo;
	}
	cout<<endl;
}


int fila::retorno( int exe){
	noh *aux;
	aux= inicio;
	for( int i=0; i<exe; i++){
		aux = aux->proximo;
	}
	return aux->dado;
}

void fila::insere(int dado, int pos){
	noh *aux;
	noh *aux2= new noh( dado);
	noh *aux3;
	int n=0;
	aux= inicio;
	while( n < pos-1){
		aux= aux->proximo;
		n++;
	}
	aux3= aux->proximo;
	aux->proximo = aux2;
	aux2->proximo= aux3;
	
}

int main(int argc, char **argv)
{
	fila L1, L2;
	int dado,cont=0;
	char opcao ,opcao1;
	
	cin>>opcao;
	while( opcao != 't'){
		if( opcao == 'i'){
			cin>>opcao1;
			cont++;
			if( opcao == 'a'){
				cin>>dado;
				L1.inserir(dado);
			}
			else{
				cin>>dado;
				L2.inserir(dado);
			}
		}
		else if( opcao == 'e'){
			cin>>opcao;
			if( opcao == 'a'){
				L1.imprimi();
			}
			else{
				L2.imprimi();
			}
		}
		else if( opcao == 'm'){
			fila L3;
			for( int i=0; i<cont; i++){
				int dado=0;
				dado= L1.retorno( i);
				L3.inserir( dado);
				dado= L2.retorno( i);
				L3.inserir( dado);
				}
				L3.imprimi();
				cin>>opcao;
			
		}
	}
	return 0;
}


