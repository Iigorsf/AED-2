#include <iostream>
#include <string>

using namespace std;

const int UMPRIMO = 39;

int funcaoHash(string s, int M) {
    int h = 0;
    for (unsigned i = 0; i < s.length(); i++)
        h = (UMPRIMO * h + s[i]) % M;
    return h;
}

class noh {
    friend class tabelaHash;
    private:
        string chave;
        string valor;
        noh* proximo = NULL;
    public:
        noh(string c, string v) {
            chave = c;
            valor = v;
        }
};

class tabelaHash {
    private:
        // vetor de ponteiros de nÃ³s
        noh** elementos;
        int capacidade;
    public:
        // construtor padrÃ£o
        tabelaHash(int cap = 100);
        // destrutor
        ~tabelaHash();
        // insere um valor v com chave c
        void insere(string c, string v);
        // recupera um valor associado a uma dada chave
        string recupera(string c);
        // altera o valor associado a uma chave
        void altera(string c, string v);
        // retira um valor associado a uma chave
        void remove(string c);
        // percorrendo a tabela hash (para fins de debug)
        void percorre();
};

// construtor padrÃ£o
tabelaHash::tabelaHash(int cap) {
    elementos = new noh*[cap];
    capacidade = cap;
    for (int i = 0; i < cap; i++)
        elementos[i] = NULL;
}

// destrutor
tabelaHash::~tabelaHash() {
    for (int i=0; i < capacidade; i++) {
        noh* atual = elementos[i];
        // percorre a lista removendo todos os nÃ³s
        while (atual != NULL) {
            noh* aux = atual;
            atual = atual-> proximo;
            delete aux;
        }
    }
    delete[] elementos;
}

// Insere um valor v com chave c.
void tabelaHash::insere(string c, string v) {
    //  CODIGO A SER DESENVOLVIDO
}

// recupera um valor associado a uma dada chave
string tabelaHash::recupera(string c) {
    int h;
    h = funcaoHash(c, capacidade);

    if ((elementos[h] != NULL) and (elementos[h]->chave == c)) {
        return elementos[h]->valor;
    } else {
        noh* atual = elementos[h];

        while ((atual != NULL) and (atual->chave != c)) {
            atual = atual->proximo;
        }

        if ((atual != NULL) and (atual->chave == c)) {
            return atual->valor;
        } else {
            return "NAO ENCONTRADO!";
        }
    }
}

// altera o valor associado a uma chave
void tabelaHash::altera(string c, string v) {
    //  CODIGO A SER DESENVOLVIDO

    // imprime "ERRO NA ALTERACAO!" na saÃ­da padrÃ£o caso tente alterar
    // elemento nÃ£o existente na tabela
}

// retira um valor associado a uma chave
void tabelaHash::remove(string c) {
    //  CODIGO A SER DESENVOLVIDO

    // imprime "ERRO NA REMOCAO!" na saÃ­da padrÃ£o caso tente remover
    // elemento nÃ£o existente na tabela
}

// percorre a tabela hash, escrevendo as listas de itens (para fins de debug)
void tabelaHash::percorre( ) {
    noh* atual;
    for (int i = 0; i < capacidade; i++) {
        cout << i << ":";
        atual = elementos[i];
        while (atual != NULL) {
            cout << "[" << atual->chave << "/"
                 << atual->valor << "]->";
            atual = atual->proximo;
        }
        cout << "NULL  ";
    }
}

int main( ) {
    tabelaHash th(10);
    int qtdade;
    string chave;
    string valor;

    // insercao na tabela
    cin >> qtdade;
    for (int i=0; i < qtdade; i++) {
        cin >> chave;
        cin >> valor;
        th.insere(chave,valor);
    }

    // altera valores
    cin >> qtdade;
    for (int i=0; i < qtdade; i++) {
        cin >> chave;
        cin >> valor;
        th.altera(chave,valor);
    }

    // remove valores
    cin >> qtdade;
    for (int i=0; i < qtdade; i++) {
        cin >> chave;
        th.remove(chave);
    }

    // recupera valores
    cin >> qtdade;
    for (int i=0; i < qtdade; i++) {
        cin >> chave;
        cout << th.recupera(chave) << endl;
    }

    // percorre a tabela
    cout << endl;
    th.percorre();
    cout << endl;

    return 0;
}
