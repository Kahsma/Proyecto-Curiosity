#ifndef _TADCOMANDOS_H_
#define _TADCOMANDOS_H_

#include <string>
#include <iostream>
#include <vector>
//Nombres : Alberto Vigna , Alejandro Salamanca ,Andres Salamanca , Camilo Martinez

class Tadcomandos
{
  protected:
  char tipo_comando;
  std::string nombre_del_comando;
  std::vector<std::string> parametros;

  public:

  //constructor
  Tadcomandos();
  Tadcomandos(char comando_comando , std::string nombre_comando);

  // Memory Wipe
  ~Tadcomandos();

  // Funciones del TAD Comandos (en el mismo orden que en el documento)
  char get_tipo();
  void set_tipo(char tipo_comando);

  std::string get_nombre_del_comando();
  void set_nombre_del_comando(std::string nombre_del_comando);

  std::vector<std::string> get_parametros();
  void set_parametros(std::vector<std::string> parametros);
};


#endif