#include <iostream>

using namespace std;

class No {
private:
  int dados;
  No *esquerda;
  No *direita;
public:
  No(int dados) {
    this->dados = dados;
    esquerda = NULL;
    direita = NULL;
  }

  int getDados() {
    return dados;
  }

  No *getEsquerda() {
    return esquerda;
  }

  No *getDireita() {
    return direita;
  }

  No *setEsquerda(No *esq) {
    return esquerda = esq;
  }

  No *setDireita(No *dir) {
    return direita = dir;
  }
};

class Arvore {
private:
  No *raiz;

public:
  Arvore() {
    raiz = NULL;
  }

  No *getRaiz() {
    return raiz;
  }

  void inserir(int valor) {
    if(raiz == NULL) {
      raiz = new No(valor);
    } else {
      inserirAux(raiz, valor);
    }
  }

  void inserirAux(No *no, int valor) {
    if(valor < no->getDados()) {
      if (no->getEsquerda() == NULL) {
        No *novoNo = new No(valor);
        no->setEsquerda(novoNo);
      } else {
        inserirAux(no->getEsquerda(), valor);
      }
    }
    else{
      if (no->getDireita() == NULL) {
        No *novoNo = new No(valor);
        no->setDireita(novoNo);
      } else {
        inserirAux(no->getDireita(), valor);
      }
    }
  }

  void getLeaves(No *no) {
    if (no->getDireita() == NULL && no->getEsquerda() == NULL) {
      cout << no->getDados() << " ";
    } else {
      if (no->getDireita() != NULL) {
        getLeaves(no->getDireita());
      }
      if (no -> getEsquerda() != NULL) {
        getLeaves(no->getEsquerda());
      }
    }
  }

  void getGrau(No *no) {
    if (no->getDireita() == NULL && no->getEsquerda() == NULL) {
      cout << "Grau do nó " << no->getDados() << ": 0\n";
    } else if(no->getDireita() != NULL && no->getEsquerda() != NULL) {
      cout << "Grau do nó " << no->getDados() << ": 2\n";
      getGrau(no->getDireita());
      getGrau(no->getEsquerda());
    } else {
      cout << "Grau do nó " << no->getDados() << ": 1\n";
      if(no->getDireita() != NULL) {
        getGrau(no->getDireita());
      } else {
        getGrau(no->getEsquerda());
      }
    }
  }

  int getProfundidade(No *no, int ancestrais) {
    if (no == NULL) {
      return 0;
    } else {
      return ancestrais + 1;
      }
    }

  void printProfundidade(No *no, int ancestrais) {
    if(no->getEsquerda() != NULL) {
      cout << "Profundidade do nó " << no->getEsquerda()->getDados() << ": " << getProfundidade(no->getEsquerda(), ancestrais) << "\n";
      printProfundidade(no->getEsquerda(), ancestrais + 1);
      }
    if(no->getDireita() != NULL) {
      cout << "Profundidade do nó " << no->getDireita()->getDados() << ": " <<     getProfundidade(no->getDireita(), ancestrais) << "\n";
      printProfundidade(no->getDireita(), ancestrais + 1);
    }
  }

  void printNivel(No *no, int ancestrais) {
      if(no->getEsquerda() != NULL) {
        cout << "Nível do nó " << no->getEsquerda()->getDados() << ": " << getProfundidade(no->getEsquerda(), ancestrais) << "\n";
        printNivel(no->getEsquerda(), ancestrais + 1);
        }
      if(no->getDireita() != NULL) {
        cout << "Nível do nó " << no->getDireita()->getDados() << ": " <<     getProfundidade(no->getDireita(), ancestrais) << "\n";
        printNivel(no->getDireita(), ancestrais + 1);
      }
    }

  int getAltura(No *no) {
    int alturaEsq = -1;
    int alturaDir = -1;

    if(raiz != NULL) {
      if (no->getEsquerda() != NULL) {
        alturaEsq = getAltura(no->getEsquerda());
      }
      if (no->getDireita() != NULL) {
        alturaDir = getAltura(no->getDireita());
      }
      return max(alturaEsq, alturaDir) + 1;
    }
    return 0;
  }


  void printAltura(No *no) {
    if(no->getEsquerda() != NULL) {
      cout << "Altura do nó " << no->getEsquerda()->getDados() << ": " << getAltura(no->getEsquerda()) << "\n";
      printAltura(no->getEsquerda());
      }
    if(no->getDireita() != NULL) {
      cout << "Altura do nó " << no->getDireita()->getDados() << ": " <<     getAltura(no->getDireita()) << "\n";
      printAltura(no->getDireita());
    }
  }

  void getSubarvore(No *no) {
      if(no != raiz) {
        cout << "Subárvore do nó " << no->getDados() << ": ";
        print(no);
        cout << "\n";
      }
      if (no->getEsquerda()) {
        getSubarvore(no->getEsquerda());
      }
      if (no->getDireita()) {
        getSubarvore(no->getDireita());
      }
    };

  void print(No *no) {
    cout << no->getDados() << " ";
    if (no->getEsquerda() != NULL) {
      print(no->getEsquerda());
    }
    if (no->getDireita() != NULL) {
      print(no->getDireita());
    }
  } 
};

int main() {
  Arvore arvore = Arvore();
  arvore.inserir(10);
  arvore.inserir(5);
  arvore.inserir(11);
  arvore.inserir(4);
  arvore.inserir(12);
  arvore.inserir(3);
  arvore.inserir(2);
  cout << "a) ";
  arvore.print(arvore.getRaiz());
  cout << "\n\nb) ";
  arvore.getLeaves(arvore.getRaiz());
  cout << "\n\nc) ";
  arvore.getGrau(arvore.getRaiz());
  cout << "\nd) ";
  arvore.printAltura(arvore.getRaiz());
  cout << "\ne) ";
  arvore.printProfundidade(arvore.getRaiz(), 0);
  cout << "\nf) ";
  arvore.printNivel(arvore.getRaiz(), 0);
  cout << "\ng) ";
  arvore.getSubarvore(arvore.getRaiz());
}