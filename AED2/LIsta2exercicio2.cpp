#include <iostream>
using namespace std;

class noh{
	friend class lista;
	
	private:
	int numero;
	noh *proximo;
	noh *anterior;
	
	public:
	noh( int num);
	
};

noh::noh( int num){
	numero = num;
	proximo = NULL;
	anterior = NULL;
}

class lista{
	
	private:
	noh *inicio;
	noh *fim;
	int tamanho;
	
	public:
	lista();
	~lista();
	int retorno( int exe);
	void inserir( int num);
	void insere( int a, int local);
	void imprimir();
	
};

lista::lista(){
	inicio = NULL;
	fim = NULL;
	tamanho = 0;
}

lista::~lista(){
	noh *aux;
	
	aux= inicio;
	while( aux != NULL){
		noh *del= aux;
		aux= aux->proximo;
		delete del;
	}
}

void lista::inserir( int num){
	noh *aux = new noh( num);
	
	if( inicio == NULL){
		inicio= aux;
		fim= aux;
	}
	else{
		fim->proximo= aux;
		aux->anterior = fim;
		fim= aux;
	}
	tamanho++;
}

void lista::insere(int dado, int pos){
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
	aux2->anterior= aux;
	aux3->anterior= aux2;
	aux2->proximo= aux3;
	
}

int lista::retorno( int exe){
	noh *aux;
	aux= inicio;
	for( int i=0; i<exe; i++){
		aux = aux->proximo;
	}
	return aux->numero;
}

void lista::imprimir(){
	
	noh *aux;
	aux= inicio;
	while ( aux != NULL){
		cout<<aux->numero<<" ";
		aux= aux->proximo;
	}
	cout<<endl;
}

int main(int argc, char **argv)
{
	lista L1, L2;
	int n, p,num;
	cin>>n;
	
	for( int i=0; i<n; i++){
		cin>>num;
		L1.inserir( num);
	}
	
	cin>>n;
	
	for( int i=0; i<n; i++){
		cin>>num;
		L2.inserir( num);
	}
	
	cin>>p;
	
	for( int i=n-1; i>-1; i--){
		int dado;
		dado = L2.retorno( i);
		L1.insere( dado ,  p);
	}
	
	L1.imprimir();
	
	return 0;
}

