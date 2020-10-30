#include <iostream>

using namespace std;

typedef int Dado;

class noh {
    friend class lista;
    private:
        const Dado dado;
        noh* proximo;
    public:
        noh(Dado d = 0);
};

noh::noh(Dado d) : dado(d) {
    proximo = NULL;
}

class lista {
    private:
        noh* primeiro;
        noh* ultimo;
        int tamanho;
    public:
        lista();
        ~lista();
        void insere(Dado dado);
        void insere(Dado dado, int pos);
        void remove(int posicao);
        int procura(Dado valor);
        void imprime();
        inline bool vazia();
};

// constrÃ³i uma lista inicialmente vazia
lista::lista() {
    tamanho = 0;
    primeiro = NULL;
    ultimo = NULL;
}

lista::~lista() {
    noh* iter = primeiro;
    noh* proximo = NULL;
    while (iter != NULL) {
        proximo = iter->proximo;
        delete iter;
        iter = proximo;
    }
}

// mÃ©todo bÃ¡sico que *percorre* a lista, imprimindo seus elementos
void lista::imprime() {
    noh* aux = primeiro;
    while (aux != NULL) {
        cout << aux->dado << " ";
        aux = aux->proximo;
    }
    cout << endl;
}

// insere por padrÃ£o no final da lista
void lista::insere(Dado dado) {
	noh *ins = new noh(dado);
	
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

// insere um dado em uma determinada posiÃ§Ã£o da lista
void lista::insere(Dado dado, int posicao) {
    noh *ins = new noh(dado);
    
    if( (posicao <= tamanho) and (posicao>= 0)){
		if( primeiro== NULL ){
			primeiro = ins;
			ultimo = ins;
		}
		else if( posicao==0){
			ins->proximo = primeiro;
			primeiro = ins;
		}
		else if(posicao==tamanho){
			ultimo->proximo = ins;
			ultimo = ins;
		}
		else{
			noh *aux = primeiro;
			int posaux=0;
			while ( posaux < (posicao-1)){
				aux = aux->proximo;
				posaux++;
			}
			ins->proximo = aux->proximo;
			aux->proximo = ins;
		}
		tamanho++;
	}
	else{
		cout<< "Posicao Inexistente" << endl;
		exit(EXIT_FAILURE);
	}
}

// remove o item da posiÃ§Ã£o passada por parÃ¢metro
// AtenÃ§Ã£o - o cÃ³digo deve tratar de posiÃ§Ã£o invÃ¡lidas
void lista::remove(int posicao) {
    if((posicao<tamanho) and (posicao>=0)){
		if(posicao==0){
			noh *aux = primeiro;
			primeiro = primeiro->proximo;
			delete aux;
		}
		else{
			noh* aux = primeiro->proximo;
			noh* ant = primeiro;
			int posaux = 1;
			while ((aux!=NULL) and (posaux < posicao)){
				ant = aux;
				aux = aux->proximo;
				posaux++;
			}
			if(aux == ultimo){
				ant->proximo = NULL;
				ultimo = ant;
				delete aux;
			}
			else{
				ant->proximo = aux->proximo;
				delete aux;
			}
		}
		tamanho--;
	}
	else{
		cout<< "posicao inexistente!"<<endl;
		exit(EXIT_FAILURE);
	}
}

// procura por um elemento e retorna a posiÃ§Ã£o ou -1 se nÃ£o encontrado
int lista::procura(Dado valor) {
    noh *aux = primeiro;
    int posaux = 0;
    while ((aux != NULL) and (aux->dado != valor)){
		posaux++;
		aux= aux->proximo;
	}
	if( aux == NULL){
		posaux = -1;
	}
	return posaux;
}

// verifica se a lista estÃ¡ vazia
inline bool lista::vazia() {
	
    return primeiro==NULL;
				
}

int main() { // NÃƒO MODIFIQUE!
    lista minhaLista;
    char opcao;
    int valor, pos;
    cin >> opcao;
    while (opcao != 'Q') {
        switch(opcao) {
            case 'I':
                cin >> valor;
                minhaLista.insere(valor);
                break;
            case 'W':
                cin >> valor;
                cin >> pos;
                minhaLista.insere(valor, pos);
                break;
            case 'P':
                cin >> valor;
                cout << minhaLista.procura(valor) << endl;
                break;
            case 'R':
                cin >> pos;
                minhaLista.remove(pos);
                break;
            case 'V':
                cout << minhaLista.vazia() << endl;
                break;
        }
        cin >> opcao;
    }
    minhaLista.imprime();
    return 0;
}
