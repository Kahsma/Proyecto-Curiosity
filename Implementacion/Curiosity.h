#ifndef _CURIOSITY_H_
#define _CURIOSITY_H_
#include <queue>
#include <list>
#include"Comandos.h"
#include"Elementos.h"
#include "QuadTree.h"
#include <vector>
using namespace std;

class Curiosity
{
private:
  queue<Comandos> ColaDeComandos;
  list<Elementos> listaDeElementos;
  quadTree arbolElementos;
public:
  // Constructor 
  Curiosity();

  // Memory Wipe
  ~Curiosity();

  // Funciones
  queue<Comandos> get_queue_de_comandos();
  void set_queue_de_comandos(queue<Comandos> ColaDeComandos);

  list<Elementos> get_lista_de_elementos ();
  void set_lista_de_elementos(list<Elementos> lista_elementos);

  bool agregar_comando(Comandos comando);
  bool borrar_comando(Comandos comando);

  bool agregar_elemento (Elementos elementos);
  bool agregar_elemento2(Elementos elementos);
  bool borrar_elemento (Elementos elementos);
  void enCuadrante(float x1,float x2,float y1,float y2);
  void imprimirarbolNivel();
  bool NivelCuadrante(float x1,float x2,float y1,float y2);

};
#include "Curiosity.hxx"
#endif