#include <iostream>
using namespace std;

class noh{
	friend class lista;
	private:
	
	string nome;
	int matricula;
	noh *proximo;
	noh *anterior;
	public:
	noh ( int matricula = 0, string nome= " ");
};

noh::noh(int matr, string name) {
	matricula = matr;
	nome = name;
	proximo = NULL;
	anterior = NULL;
}

class lista{
	private:
	noh* primeiro;
	noh* ultimo;
	int tamanho;
	public:
	lista();
	~lista();
	void insere(int matricula, string nome);
	void remove( int matricula);
	void imprimeif();
	void imprimefi();
};

lista::lista(){
	primeiro = NULL;
	ultimo = NULL;
	tamanho=0;
}

lista::~lista(){
	noh* iter = primeiro;
    noh* proximo = NULL;
    while (iter != NULL) {
        proximo = iter->proximo;
        delete iter;
        iter = proximo;
    }
}

void lista::insere(int matricula, string nome){
	noh *novo = new noh(matricula, nome);
	if( primeiro==NULL){
		primeiro= novo;
		ultimo= novo;
	}
	else{
		noh *aux=primeiro;
		primeiro = novo;
		novo->proximo = aux;
		aux->anterior = novo;
	}
	tamanho++;
}
	
void lista::remove(int matricula){
	noh *aux=primeiro;
	while(aux!=NULL and aux->matricula!=matricula){
		aux=aux->proximo;
	}
	if(aux==NULL){
 	cout<<"ERRO"<<endl;
 	}
 	else if((aux==primeiro) and (aux==ultimo)){
		primeiro=NULL;
		ultimo=NULL;
		delete aux;
		tamanho--;
	}
 	else if(aux==primeiro){
		primeiro=primeiro->proximo;
 	    primeiro->anterior=NULL;
 	    delete aux;
 	    tamanho--;
 	 }
 	 else if(aux==ultimo){
 	    ultimo=ultimo->anterior;
 	    ultimo->proximo=NULL;
 	    delete aux;
 	    tamanho--;
 	}
 	else{
		noh *auxant=aux->anterior, *auxpos=aux->proximo;
 	    auxant->proximo=auxpos;
 	    auxpos->anterior=auxant;
 	    delete aux;
 	    tamanho--;
    }
}

void lista::imprimeif(){
	noh *aux= primeiro;
	while( aux!= NULL){
		cout<<aux->matricula<<" "<<aux->nome<<" ";
		aux = aux->proximo;
	}
	cout<<endl;
}
	
void lista::imprimefi(){
	noh *aux=ultimo;
	while( aux!=NULL){
		cout<<aux->matricula<<" "<<aux->nome<<" ";
		aux = aux->anterior;
	}
}			
				
			
int main(int argc, char **argv)
{
	lista minhalista;
	string x;
	string nome;
	int matricula;
	cin>>x;
	while( x!="t"){
		if( x=="i"){
			cin>>matricula>>nome;
			minhalista.insere(matricula, nome);
		}
		else if( x=="r"){
			cin>>matricula;
			minhalista.remove( matricula);
		}
		else if( x=="ed"){
			minhalista.imprimeif();
		}
		else if( x=="er"){
			minhalista.imprimefi();
		}
		cin>>x;
	}
	
	return 0;
}

