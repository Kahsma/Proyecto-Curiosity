#include <string>
#include <iostream>

using namespace std;

class shell {
private:
  string command;

public:
  //Constructor
  shell();
  shell(string commandd);
  
  //Memomory Wipe
  ~shell();
  
  //Functions (destructor)
  void verificarComandos(char comm[]);
  void help();
  void iniciarShell();
  void cargarComandos();
  void cargarElementos();
  void agregarMovimiento();
  void agregarAnalisis();
  void agregarElemento();
  void guardar();
  void simularComandos();
  void enCuadrante();
  void salir();
  void ubicarElementos();
  void crearMapa();
  void rutaMasLarga();
};