#include <iostream>
using namespace std;

typedef float Dado;

class noh {
  friend class listadup;
  private:
    const Dado dado;
    noh* proximo;
    noh* anterior;
  public:
    noh(Dado d = 0) : dado(d) {
      proximo = NULL;
      anterior = NULL;
    }
};

// lista dinamicamente encadeada
class listadup {
  private:
    noh* primeiro;
    noh* ultimo;
    int tamanho;
  public:
    listadup() {
      // constrói uma lista inicialmente vazia
      tamanho = 0;
      primeiro = NULL;
      ultimo = NULL;
    };
    ~listadup() {
      // destroi a lista
      noh* atual = primeiro;
      while (atual != NULL) {
        noh* aux = atual;
        atual = atual->proximo;
        delete aux;
      }
    };
    inline void insere(Dado dado) {
      noh *novo = new noh(dado);
      
      if( primeiro == NULL ){
		  primeiro = novo;
		  ultimo = novo;
	  }
	  else{
		  ultimo->proximo = novo;
		  novo->proximo = NULL;
	  }
	  tamanho++;
};
    
listadup* separa(int n) {
		if( n>=0 and n<tamanho){
			if( n==0){
				noh *aux=primeiro;
				primeiro=aux->proximo;
				aux->proximo = NULL;
			}
			else{
				noh *aux=primeiro;
			    noh *posaux=primeiro->proximo;
			    int cont=0;
			    while( (aux!=NULL) and (cont<=n)){
					aux= posaux;
				    posaux= posaux->proximo;
				    cont++;
				    }
				primeiro= posaux;
				aux->proximo= NULL;
					}
				}
				else{
			cout<<"ERRO";
			return NULL;
		}
      // transfere os elementos a partir de n (indices iniciam em 0) para uma nova listadup
      // A nova lista deverá ser desalocada pelo subprograma que for fazer uso dela!
      // TODO - implementar
};
    
void imprime() {
      // método básico que *percorre* uma lista, imprimindo seus elementos
      noh* aux = primeiro;
      
      if (aux == NULL) {
        cout << "vazio!";
      } else {
        while (aux != NULL) {
          cout << aux->dado << " ";
          aux = aux->proximo;
        }
      }
      
      cout << " <> ";
      
      // imprime reverso (para mostrar duplo encadeamento)
      aux = ultimo;
      if (aux == NULL) {
        cout << "vazio!";
      } else {
        while (aux != NULL) {
          cout << aux->dado << " ";
          aux = aux->anterior;
        }
      }
      
      cout << endl;
    };
};


// NÃO MODIFICAR
int main() {
  listadup* minhaLista = new listadup;
  
  char opcao;
  float valor;

  do {
    cin >> opcao;

    switch(opcao) {
      case 'I':
        cin >> valor;
        minhaLista->insere(valor);
        break;
      case 'S':
        cin >> valor;
        listadup* outraLista = minhaLista->separa(valor);
        if (outraLista != NULL) {
          outraLista->imprime();
          delete outraLista;
        } 
        break;
    }
  } while (opcao != 'Q');

  minhaLista->imprime();
  
  delete minhaLista;

  return 0;
}
