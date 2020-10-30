#include <iostream>

using namespace std;

class noh {
friend class pilha;
private:
    int dado;
    noh* prox;
    public:
    noh( int d){
		dado=d;
		prox= NULL;
	}
};

class pilha {
private:
    noh* topo;
    int tamanho;
    
public:
    pilha();
    ~pilha();
    void empilha(int d);
    int desempilha(); // retorna o topo da pilha
    int espia(); // espia o topo da pilha
    bool vazia();
    void limpaPilha(); //limpa a pilha    
    void inverter();
};


pilha::pilha(){
    tamanho = 0;
    topo = NULL;
}

pilha::~pilha(){
    while (topo != NULL) {
        desempilha();
    }
}

void pilha::empilha(int d) {
    noh* temp = new noh( d);
    if( topo == NULL){
		topo = temp;
	}
	else{
		temp->prox = topo;
		topo = temp;
	}
    tamanho++;    
}

int pilha::desempilha() {
    int removido;
    noh* temp;
    removido = topo->dado;
    temp = topo;
    topo = topo->prox;
    delete temp;
    tamanho--;
    return removido;    
}

int pilha::espia(){
    return topo->dado;
}

void pilha::limpaPilha(){
    while (topo != NULL) {
        cout << desempilha() << endl;
    }
}
    
bool pilha::vazia() {
    return (topo == NULL);
}

void pilha::inverter(){
	int tam= tamanho;
	int v[tam];
	for( int i=0; i<tam; i++){
		v[i]= desempilha();
	}
	for( int i=0; i<tam; i++){
		empilha( v[i]);
	}
}

int main() {
    pilha p1;
    int n, dado;
    cin >> n;
    int i=0;
    while (i < n) {
		cin>>dado;
        p1.empilha(dado);
        i++;
    }
    p1.inverter();
    
    while (not p1.vazia()) {
        cout << p1.desempilha() << " ";
    }
    cout << endl;

    return 0;
}
