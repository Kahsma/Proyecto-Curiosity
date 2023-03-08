#ifndef _CURIOSITY_H_
#define _CURIOSITY_H_
#include <queue>
#include"Tadcomandos.h"
#include"Elementos.h"
using namespace std;

class curiosity{
private:
queue<Tadcomandos> ColaDeComandos;
public:
curiosity();
queue<Tadcomandos> get_queue_de_comandos();
void set_queue_de_comandos(queue<Tadcomandos>);
bool agregar_comando(Tadcomandos comando);
bool borrar_comando(Tadcomandos comando);
bool agregar_elemento (Elementos elementos);
bool borrar_elemento (Elementos elementos);
~curiosity();

};
#endif