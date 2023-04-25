#ifndef __QUADTREE__H__
#define __QUADTREE__H__
#include "NodoQuadTree.h"
#include "Elementos.h"
#include <vector>
class quadTree
{
protected:
nodoQuad* raiz;
public:
quadTree();
quadTree(Elementos val);
~quadTree();
Elementos datoRaiz();
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
vector<Elementos>  enCuadrante(float x1,float x2,float y1,float y2);
vector<Elementos>  enCuadranteAux(nodoQuad* nodo,float x1,float x2,float y1,float y2);
bool nivelOrdenCuadrante(float x1,float x2,float y1,float y2);
void nivelOrdenCuadranteAux(nodoQuad* nodo, float x1,float x2,float y1,float y2);
};
#include "QuadTree.cxx"

#endif