#include "Curiosity.h"
#include <list>
using namespace std;
// Constructor
Curiosity::Curiosity()
{
}

// Destructor
Curiosity::~Curiosity() {}

// Funciones del TAD Curiosity
// Funciones Queue de Comandos
queue<Comandos> Curiosity::get_queue_de_comandos()
{
  return ColaDeComandos;
}

void Curiosity::set_queue_de_comandos(queue<Comandos> ColaDeComandos)
{
  this->ColaDeComandos = ColaDeComandos;
}

list<Elementos> Curiosity::get_lista_de_elementos()
{
  return listaDeElementos;
}

void Curiosity::set_lista_de_elementos(list<Elementos> lista_elementos)
{
  listaDeElementos = lista_elementos;
}

// Funciones comandos
bool Curiosity::agregar_comando(Comandos comando)
{
  bool resultado_agregar_comando = false;
  ColaDeComandos.push(comando);
  resultado_agregar_comando = true;
  return resultado_agregar_comando;
}

bool Curiosity::borrar_comando(Comandos comando)
{
  bool resultado_borrar_comando = false;

  return resultado_borrar_comando;
}

//Funciones elemento
bool Curiosity::agregar_elemento(Elementos elementos)
{
  bool resultado_agregar_elemento = false;
  listaDeElementos.push_back(elementos);
  resultado_agregar_elemento = true;
  return resultado_agregar_elemento;
}

bool Curiosity::borrar_elemento(Elementos elementos)
{
  bool resultado_borrar_elemento = false;
  return resultado_borrar_elemento;
}

void Curiosity::enCuadrante(float x1,float x2,float y1,float y2){

  vector<Elementos> results = arbolElementos.enCuadrante(x1,x2,y1,y2);
  for(auto ele : results){
    std::cout << ele  <<std::endl;
  }

}
bool Curiosity::NivelCuadrante(float x1,float x2,float y1,float y2){
  bool encontradso =  false;
  encontradso = arbolElementos.nivelOrdenCuadrante(x1,x2,y1,y2);
  return encontradso;
}

bool Curiosity::agregar_elemento2(Elementos elementos)
{
  bool resultado_agregar_elemento = false;
  resultado_agregar_elemento = arbolElementos.insertar(elementos);
  //resultado_agregar_elemento=true;
  //std::cout<<"\n";
  //arbolElementos.nivelOrden();
  //std::cout<<"\n";
  //arbolElementos.posOrden();
  return resultado_agregar_elemento;
}

// bool Curiosity::borrar_elemento(Elementos elementos)
// {
//   bool resultado_borrar_elemento = false;
//   return resultado_borrar_elemento;
// }
void Curiosity::imprimirarbolNivel(){
  arbolElementos.nivelOrden();

}