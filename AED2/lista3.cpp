#include <iostream>
using namespace std;

class noh {
	friend class lista;
	private:
	int pessoas;
	int avanco;
	noh *proximo;
	public:
	noh (int dado = 0);
};

noh::noh(int dado){
	dado = dado;
	proximo = NULL;
}

class lista{
	private:
	noh *primeiro;
	noh *ultimo;
	int tamanho;
	public:
	lista();
	~lista();
	void faz(int pessoa);
	void resolve(int pessoa, int avanco);
};

lista::lista(){
	primeiro = NULL;
	ultimo = NULL;
	tamanho = 0;
}

lista::~lista(){
	noh *iter = primeiro;
    noh *proximo = NULL;
    while (iter != NULL) {
        proximo = iter->proximo;
        delete iter;
        iter = proximo;
    }
}

void lista::faz(int pessoa){
	noh *ins = new noh(pessoa);
	if( primeiro == NULL ){
		primeiro = ins;
		ultimo = ins;
		}
		else{
			ultimo->proximo = ins;
			ultimo = ins;
			}
	tamanho++;
}
void lista::resolve(int pessoas, int avanco){
	tamanho = pessoas;
		noh *aux= primeiro;
	while(tamanho>0){
		for( int i=0; i<avanco; i++){
			aux= aux->proximo;
		}
		delete aux;
		tamanho--;
	}
	cout<<aux;
}
int main()
{
	lista minhalista;
	int pessoa, avanco;
	for( int i=1; i<=pessoa; i++){
		minhalista.faz( i );
	}
	minhalista.resolve( pessoa, avanco);
	
	return 0;
}

