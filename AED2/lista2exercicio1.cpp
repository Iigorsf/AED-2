#include <iostream>
using namespace std;

class noh{
	friend class lista; 
	
	private:
	int numero;
	noh *proximo;
	noh *anterior;
	
	public:
	noh(int num);
	
};

noh::noh(int num){
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
	void inserir(int num);
	void RemoverRepetidos();
	void imprimir1();
	void imprimir2();
};
 
 lista::lista(){
	 inicio = NULL;
	 fim = NULL;
	 tamanho = 0;
 }
 
 lista::~lista(){
	 noh* iter = inicio;
     noh* proximo = NULL;
     while (iter != NULL) {
        proximo = iter->proximo;
        delete iter;
        iter = proximo;
        }
}
 
 void lista::inserir(int num){
	 noh *aux= new noh( num);
	 
	 if( inicio == NULL){
		 inicio = aux;
		 fim = aux;
	 }
	 else{
		fim->proximo = aux;
		aux->anterior = fim; 
		fim = aux;
	 }
	 tamanho++;
 }
 
 void lista::RemoverRepetidos(){
	 noh *aux;
	 noh *help;
	 aux= inicio;
	 
	 while( aux != NULL){
		 help = aux->proximo;
		 while( help != NULL){
			 if( aux->numero == help->numero){
				 noh *del;
				 del = help;
				 help= help->anterior;
				 help->proximo = del->proximo;
				 if( del == fim){
					 fim = del->anterior;
				 }
				 else{
					 noh *del2;
					 del2= del->proximo;
					 del2->anterior= help;
					 }
				 delete del;
				 tamanho--;
			 }
			 help= help->proximo;
		 }
		 aux = aux->proximo;
	 }
 }
 
  void lista::imprimir1(){
	 noh *aux;
	 aux= inicio;
	 while( aux != NULL){
		 cout<<aux->numero<<" ";
		 aux= aux->proximo;
	 }
	 cout<<endl<<tamanho<<endl;
 } 
 
 void lista::imprimir2(){
	 noh *aux;
	 aux= fim;
	 while( aux != NULL){
		 cout<<aux->numero<<" ";
		 aux= aux->anterior;
	 }
 }  
 
 
int main(int argc, char **argv)
{
	lista minhalista;
	
	int n,num;
	cin>>n;
	
	for( int i=0; i<n; i++){
		cin>>num;
		minhalista.inserir( num);
	}
	
	minhalista.RemoverRepetidos();
	
	minhalista.imprimir1();
	minhalista.imprimir2();
	
	return 0;
}

