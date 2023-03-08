#ifndef _CURIOSITY_H_
#define _CURIOSITY_H_
#include <queue>
#include"Comandos.h"
#include"Elementos.h"
using namespace std;

class Curiosity
{
private:
  queue<Comandos> ColaDeComandos;

public:
  // Constructor 
  Curiosity();

  // Memory Wipe
  ~Curiosity();

  // Funciones
  queue<Comandos> get_queue_de_comandos();
  void set_queue_de_comandos(queue<Comandos> ColaDeComan ):

  bool agregar_comando(Comandos comando);
  bool borrar_comando(Comandos comando);

  bool agregar_elemento (Elementos elementos);
  bool borrar_elemento (Elementos elementos);
};
#endif