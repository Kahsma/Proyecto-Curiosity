#include <iostream>
#include <map>
#include <stdlib.h>
#include "shell.h"
// #include <conio.h>

using namespace std; 

shell::shell()
{
  command = "";
}
shell::shell(string commandd)
{
  command = commandd;
}

// - - - - - FUNCIONES IMPLEMENTADAS - - - - -
// Funcion Help-
void shell::help()
{
  cout << "Funcion de help" << endl;
}


// Funcion de inicializacion.
void shell::iniciarShell()
{
  /*if (system ("CLS")!=1){
    perror("ERROR");
  }*/
  cout << "" << endl;
  cout<<"  /$$$$$$  /$$   /$$ /$$$$$$$  /$$$$$$  /$$$$$$   /$$$$$$  /$$$$$$$$ /$$$$$$ /$$$$$$$$ /$$     /$$"<<endl;
  cout<<" /$$__  $$| $$  | $$| $$__  $$|_  $$_/ /$$__  $$ /$$__  $$|__  $$__/|_  $$_/|__  $$__/|  $$   /$$/"<<endl;
  cout<<"| $$  \\__/| $$  | $$| $$  \\ $$  | $$  | $$  \\ $$| $$  \\__/   | $$     | $$     | $$    \\  $$ /$$/ "<<endl;
  cout<<"| $$      | $$  | $$| $$$$$$$/  | $$  | $$  | $$|  $$$$$$    | $$     | $$     | $$     \\  $$$$/  "<<endl;
  cout<<"| $$      | $$  | $$| $$__  $$  | $$  | $$  | $$ \\____  $$   | $$     | $$     | $$      \\  $$/   "<<endl;
  cout<<"| $$    $$| $$  | $$| $$  \\ $$  | $$  | $$  | $$ /$$  \\ $$   | $$     | $$     | $$       | $$    "<<endl;
  cout<<"|  $$$$$$/|  $$$$$$/| $$  | $$ /$$$$$$|  $$$$$$/|  $$$$$$/   | $$    /$$$$$$   | $$       | $$    "<<endl;
  cout<<" \\______/  \\______/ |__/  |__/|______/ \\______/  \\______/    |__/   |______/   |__/       |__/    "<<endl;

  
  cout << "---------------------------------------------------" << endl;
  cout << " - - Bienvenido al sistema del robot CURIOSITY - - " << endl;
  cout << "---------------------------------------------------" << endl;
  cout << "---------------------------------------------------" << endl;
  cout << "- - - - Si necesitas ayuda utiliza /help - - - - - " << endl;
  
}


// Funcion de cargar comandos.
void shell::cargarComandos()
{
  cout << "Cargar comandos." << endl;
}


// Funcion de cargar elementos.
void shell::cargarElementos()
{
  cout << "Cargar elementos." << endl;
}


// Funcion de agregar movimiento.
void shell::agregarMovimiento()
{
  cout << "Agregar movimiento." << endl;
}


// Funcion de agregar analisis. 
void shell::agregarAnalisis()
{
  cout << "Agregar analisis." << endl;
}


// Funcion de agregar elementos.
void shell::agregarElemento()
{
  cout << "Agregar elementos." << endl;
}
void shell::guardar()
{
  cout<< "funcion guardar"<<endl;
}
void shell::simularComandos()
{
  cout << "funcion "<<endl;
}
  void enCuadrante();
  void salir();
  void ubicarELementos();
  void crearMapa();
  void rutaMasLarga();

// Funcion de guardar.

