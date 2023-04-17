#ifndef __QUADTREE__H__
#define __QUADTREE__H__
#include "NodoQuadTree.h"
#include "Elementos.cxx"
class quadTree
{
protected:
nodoQuad* raiz;
public:
quadTree();
quadTree(Elementos val);
~quadTree();
punto datoRaiz();
nodoQuad* obtenerRaiz();
void fijarRaiz(nodoQuad* n_raiz);
bool esVacio();
bool insertar(Elementos val);
void inOrden();
void preOrden();
void posOrden();
void inOrdenAux(nodoQuad* nodo);
void preOrdenAux(nodoQuad* nodo);
void posOrdenAux(nodoQuad* nodo);
void nivelOrden();
void nivelOrdenAux(nodoQuad* nodo);
};
#include "QuadTree.cxx"

#endif