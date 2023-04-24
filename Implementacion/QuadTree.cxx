#include "QuadTree.h"
#include <queue>
#include <iostream>
 // Default constructor
  quadTree::quadTree() : raiz(nullptr) {}

  // Parameterized constructor
  quadTree::quadTree(Elementos val) : raiz(new nodoQuad(val)) {}

  // Destructor
  quadTree::~quadTree() {}

  // Getter for data in the root node
  Elementos quadTree::datoRaiz() { return raiz->obtenerDato(); }

  // Getter and setter for the root node
  nodoQuad* quadTree::obtenerRaiz() { return raiz; }
  void quadTree::fijarRaiz(nodoQuad* n_raiz) { raiz = n_raiz; }

  // Function to check if the quadtree is empty
  bool quadTree::esVacio() { return raiz == nullptr; }

  bool quadTree::insertar(Elementos val) {
    if (raiz == nullptr) { // Si el árbol está vacío, se inserta en la raíz
        raiz = new nodoQuad(val);
        return true;
    } else {
        nodoQuad* actual = raiz;
        nodoQuad* padre = nullptr;
        bool izq = false; // Bandera para saber si el nuevo nodo debe ser insertado como hijo izquierdo o derecho
        // Se recorre el árbol hasta encontrar la posición donde se debe insertar el nuevo nodo
        while (actual != nullptr) {
            padre = actual;
            // Se compara la coordenada X del punto actual con la del nuevo punto
            if (val.getCoordX() < actual->obtenerDato().getCoordX()) {
                // El nuevo punto tiene una coordenada X menor, se desciende por el hijo izquierdo
                if (val.getCoordY() < actual->obtenerDato().getCoordY()) {  
                    // El nuevo punto tiene una coordenada Y menor, se desciende por el hijo sup-izq
                    actual = actual->obtenerHijoInfIzq();
                    izq = true;
                } else {
                    // El nuevo punto tiene una coordenada Y mayor o igual, se desciende por el hijo inf-izq
                    actual = actual->obtenerHijoSupIzq();
                    izq = true;
                }
            } else {
                // El nuevo punto tiene una coordenada X mayor o igual, se desciende por el hijo derecho
                if (val.getCoordY() < actual->obtenerDato().getCoordY()) {
                    // El nuevo punto tiene una coordenada Y menor, se desciende por el hijo sup-der
                    actual = actual->obtenerHijoInfDer();
                    izq = false;
                } else {
                    // El nuevo punto tiene una coordenada Y mayor o igual, se desciende por el hijo inf-der
                    actual = actual->obtenerHijoSupDer();
                    izq = false;
                }
            }
        }
        // Se crea el nuevo nodo y se inserta en el lugar correspondiente
        nodoQuad* nuevoNodo = new nodoQuad(val);
        if (izq) {
            if (val.getCoordY() < padre->obtenerDato().getCoordY()) {
                padre->fijarHijoInfIzq(nuevoNodo);
            } else {
                padre->fijarHijoSupIzq(nuevoNodo);
            }
        } else {
            if (val.getCoordY() < padre->obtenerDato().getCoordY()) {
                padre->fijarHijoInfDer(nuevoNodo);
            } else {
                padre->fijarHijoSupDer(nuevoNodo);
            }
        }
        return true;
    }
    return false; // Si llega aquí, hubo algún error al insertar el nuevo nodo
}



  // Traversal functions
  void quadTree::inOrden() {
    if (raiz != nullptr) {
      inOrdenAux(raiz);
      std::cout << std::endl;
    }
  }

  void quadTree::preOrden() {
    if (raiz != nullptr) {
      preOrdenAux(raiz);
      std::cout << std::endl;
    }
  }

  void quadTree::posOrden() {
    if (raiz != nullptr) {
      posOrdenAux(raiz);
      std::cout << std::endl;
    }
  }

  void quadTree::nivelOrden() {
    if (raiz != nullptr) {
      nivelOrdenAux(raiz);
      std::cout << std::endl;
    }
  }


  // Helper functions for traversals
  void quadTree::inOrdenAux(nodoQuad* nodo) {
    if (nodo != nullptr) {
      inOrdenAux(nodo->obtenerHijoSupIzq());
      std::cout << nodo->obtenerDato() << " ";
      inOrdenAux(nodo->obtenerHijoSupDer());
      inOrdenAux(nodo->obtenerHijoInfIzq());
      inOrdenAux(nodo->obtenerHijoInfDer());
    }
  }

  void quadTree::preOrdenAux(nodoQuad* nodo) {
    if (nodo != nullptr) {
      std::cout << nodo->obtenerDato() << " ";
      preOrdenAux(nodo->obtenerHijoSupIzq());
      preOrdenAux(nodo->obtenerHijoSupDer());
      preOrdenAux(nodo->obtenerHijoInfIzq());
      preOrdenAux(nodo->obtenerHijoInfDer());
    }
  }

  void quadTree::posOrdenAux(nodoQuad* nodo) {
    if (nodo != nullptr) {
      posOrdenAux(nodo->obtenerHijoSupIzq());
      posOrdenAux(nodo->obtenerHijoSupDer());
      posOrdenAux(nodo->obtenerHijoInfIzq());
      posOrdenAux(nodo->obtenerHijoInfDer());
      std::cout << nodo->obtenerDato() << " ";
    }
  }
  void quadTree::nivelOrdenAux(nodoQuad* nodo) {
    if (nodo != nullptr) {
      std::queue<nodoQuad*> cola;
      cola.push(nodo);
      while (!cola.empty()) {
        nodoQuad* actual = cola.front();
        cola.pop();
        std::cout << actual->obtenerDato() << " ";
        if (actual->obtenerHijoSupIzq() != nullptr) cola.push(actual->obtenerHijoSupIzq());
        if (actual->obtenerHijoSupDer() != nullptr) cola.push(actual->obtenerHijoSupDer());
        if (actual->obtenerHijoInfIzq() != nullptr) cola.push(actual->obtenerHijoInfIzq());
        if (actual->obtenerHijoInfDer() != nullptr) cola.push(actual->obtenerHijoInfDer());
      }
}
}