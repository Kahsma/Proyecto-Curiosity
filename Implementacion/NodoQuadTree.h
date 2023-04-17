#ifndef __NODOQUAD__H__
#define __NODOQUAD__H__
#include "Elementos.h"
class nodoQuad{
protected:
Elementos dato;
nodoQuad* hijoSupIzq;
nodoQuad* hijoSupDer;
nodoQuad* hijoInfIzq;
nodoQuad* hijoInfDer;
public:
nodoQuad();
nodoQuad(Elementos val);
~nodoQuad();
punto obtenerDato();
void fijaDato(Elementos val);
nodoQuad* obtenerHijoSupIzq();
nodoQuad* obtenerHijoSupDer();
nodoQuad* obtenerHijoInfIzq();
nodoQuad* obtenerHijoInfDer();
void fijarHijoSupIzq(nodoQuad* sizq);
void fijarHijoSupDer(nodoQuad* sder);
void fijarHijoInfIzq(nodoQuad* iizq);
void fijarHijoInfDer(nodoQuad* ider);
bool esHoja();
};
#include "NodoQuadTree.cxx"
#endif