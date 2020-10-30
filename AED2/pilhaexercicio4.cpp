#include <iostream>
using namespace std;

class noh{
	friend class pilha;
	private:
	string dado;
	noh* proximo;
	public:
	noh ( string dado);
};

noh::noh ( string dad){
	dado= dad;
	proximo= NULL;
}

class pilha{
	private:
	noh* top;
	int tamanho = 0;
	public:
	pilha();
	~pilha();
	void insere(string dado);
	bool vazio();
	string remove();
	void mesclar();
	void imprimi();
};

pilha::pilha(){
	top = NULL;
	tamanho = 0;
}

pilha::~pilha(){
	noh *aux;
	aux= top;
	while( top = NULL){
		noh *del;
		del = aux;
		aux = aux->proximo;
		delete del;
	}
}

void pilha::insere(string dado){
	cout<<dado<<endl;
	noh *aux= new noh( dado);
	
	if( top == NULL ){
		top = aux;
		tamanho++;
		cout<<aux->dado<<endl;
	}
	else{
		aux->proximo = top;
		top = aux;
		tamanho++;
	}
}

bool pilha::vazio(){
	if( top == NULL){
		return true;
	}
	else{
		return false;
	}
}

	
void pilha:: imprimi(){
	noh *aux;
	aux = top;
	while( aux != NULL){
		cout<<aux<<" ";
		aux= aux->proximo;
	}
	cout<<endl;
}

string pilha::remove(){
	string r;
	noh *aux;
	
	aux= top;
	r = aux->dado;
	 top=aux->proximo;
	delete aux;
	tamanho--;
	return r;
}

int main()
{
	pilha L1, L2;
	string texto, use;
	getline(cin,texto);
	float resul=0;
	while( texto != "fim"){
		int tam;
		tam= texto.size();
		for( int i=0; i<tam; i++){
			use= use + texto[i];
			if((texto[i] == '+') or (texto[i] == '-') or (texto[i] == '*') or (texto[i] == '/')){
				L2.insere( use);
				use= ' ';
				string tex;
				tex= texto[i];
				L1.insere( tex);
			}
		}
		while( !L1.vazio() ){
			/*double y;
			string z;
			z = L2.remove();
			y = (double)z;
			resul = resul+((char)L1.remove()) y;*/
		}
		cout<<resul<<endl;
		cin>>texto;
	}
	
	

	
	
	return 0; 
}
