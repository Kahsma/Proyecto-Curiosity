//Nombres : Alberto Vigna , Alejandro Salamanca ,Andres Salamanca , Camilo Martinez

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
  void cargarComandos(string nombreDocumento);
  void cargarElementos(string nombre);
  void agregarMovimiento(string tipo,int magnitud,string unidad);
  void agregarAnalisis(string tipo,string objteo, string comentario);
  void agregarElemento(string tipoComp , int tamanio,string unidadMedida,int cordx,int cordy);
  void guardar();
  void simularComandos(int x,int y);
  void enCuadrante(int x1,int x2,int y1,int y2);
  void salir();
  void ubicarElementos();
  void crearMapa();
  void rutaMasLarga();
};