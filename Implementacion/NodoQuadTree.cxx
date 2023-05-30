#include "NodoQuadTree.h"

// Default constructor
nodoQuad::nodoQuad() : dato(), hijoSupIzq(nullptr), hijoSupDer(nullptr), hijoInfIzq(nullptr), hijoInfDer(nullptr) {}

// Parameterized constructor
nodoQuad::nodoQuad(Elementos val) : dato(val), hijoSupIzq(nullptr), hijoSupDer(nullptr), hijoInfIzq(nullptr), hijoInfDer(nullptr) {}

// Destructor
nodoQuad::~nodoQuad() {}

// Getter and setter for data
Elementos nodoQuad::obtenerDato() { return dato; }
void nodoQuad::fijaDato(Elementos val) { dato = val; }

// Getters and setters for children
nodoQuad *nodoQuad::obtenerHijoSupIzq() { return hijoSupIzq; }
nodoQuad *nodoQuad::obtenerHijoSupDer() { return hijoSupDer; }
nodoQuad *nodoQuad::obtenerHijoInfIzq() { return hijoInfIzq; }
nodoQuad *nodoQuad::obtenerHijoInfDer() { return hijoInfDer; }
void nodoQuad::fijarHijoSupIzq(nodoQuad *sizq) { hijoSupIzq = sizq; }
void nodoQuad::fijarHijoSupDer(nodoQuad *sder) { hijoSupDer = sder; }
void nodoQuad::fijarHijoInfIzq(nodoQuad *iizq) { hijoInfIzq = iizq; }
void nodoQuad::fijarHijoInfDer(nodoQuad *ider) { hijoInfDer = ider; }

// Function to check if the node is a leaf
bool nodoQuad::esHoja()
{
  return hijoSupIzq == nullptr && hijoSupDer == nullptr && hijoInfIzq == nullptr && hijoInfDer == nullptr;
}