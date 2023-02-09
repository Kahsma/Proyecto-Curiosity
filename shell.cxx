#include <iostream>
#include <map>
#include <stdlib.h>
#include "shell.h"
//#include <curses.h>
//#include "conio.h"
#include <unistd.h> // for sleep()
#include <cstring>  

#include <fstream>// archivos 

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

//función para saber que coamndo pasaron 
void shell::verificarComandos(char comm[])
{
  string partido[6];
  cout<< "Verificar comandos"<< comm << sizeof(comm)<<endl;
  char *ptr; // declare a ptr pointer  
  ptr = strtok(comm, " ");
  cout<< "ptr es "<< ptr <<endl;
  int i =0;
  partido[0]=ptr;
  while (ptr != NULL)  
    {  
      i++;
      cout << ptr  << endl; // print the string token  
      ptr = strtok (NULL, " ");  
      cout << "hola"  << endl;
      partido[i]=ptr;
      cout << "hola2"  << endl;
    }

    /*if(strcpy()){
      
    }
  else if(com.compare("cargar_comandos")){
    
  }
  else if(com.compare("cargar_elementos")){
    
  }
  else if(com.compare( "agregar_movimientos")){
    
  }
  else if(com.compare( "agregar_analisis")){
    
  }
  else if(com.compare( "agregar_elementos")){
    
  }
  else if(com.compare( "guardar")){
    
  }
  else if(com.compare( "simular_comandos")){
    
  }
  else if(com.compare( "en_cuadrante")){
    
  }
  else if(com.compare("salir")){
    
  }
  else if(com.compare("ubicar_elementos")){
    
  }
  else if(com.compare("crear_mapa")){
    
  }
  else if(com.compare("ruta_mas_larga")){
    
  }*/
}

// Funcion Help-
void shell::help()
{
  cout << "Funcion de help" << endl;
    cout << "-================================================================================================-" << endl;
    cout << "-================================== Pediste ayuda? Tranquilo :) =================================-" << endl;
    cout << "-================================================================================================-" << endl;
    cout << "" << endl;
    cout << "'cargar_comandos' es usado Para la carga en memoria los comandos de desplazamiento contenidos en  " << endl;
    cout << "el archivo identificado por 'nombre_archivo1'." << endl;
    cout << "" << endl;
    cout << "'cargar_elementos' es usado para Carga en memoria los datos de puntos de interés o elementos      " << endl;
    cout << "contenidos en el archivo identificado por nombre_archivo." << endl;
    cout << "" << endl;
    cout << "'agregar_movimiento' es usado para agrega el comando de movimiento descrito a la lista de comandos" << endl;
    cout << "del robot “Curiosity”. El movimiento puede ser de dos tipos: avanzar o girar." << endl;
    cout << "" << endl;
    cout << "'agregar_analisis' es usado para agregar el comando de análisis descrito a la lista de comandos   " << endl;
    cout << "del robot “Curiosity”. El análisis puede ser de tres tipos: fotografiar, composicion o perforar.  " << endl;
    cout << "" << endl;
    cout << "'agregar_elemento' es usado para agregar el componente o elemento descrito a la lista de puntos de" << endl;
    cout << "interés del robot “Curiosity”. El tipo de componente puede ser uno entre roca, crater, monticulo  " << endl;
    cout << "o duna." << endl;
    cout << "" << endl;
    cout << "'guardar' es usado para guardar en el archivo." << endl;
    cout << "" << endl;
    cout << "'simular_comandos' es usado para Permite simular el resultado de los comandos de movimiento que se" << endl;
    cout << "enviarán al robot “Curiosity” desde la Tierra." << endl;
    cout << "'salir' termina de ejecutar la aplicacion (como obvio no? jajaj)" << endl;
    cout << "-================================================================================================-" << endl;
}


// Funcion de inicializacion.
void shell::iniciarShell()
{
  //Borrar consola
  if (system ("clear")==-1)
  {
    cout<<"ERROR"<<endl;
  }

  cout << "Cargando, por favor espere..." << endl;
  cout << '-' << flush;
    for (int i = 0; i < 0; i++ ) 
    {
        std::cout << "\b\b\b\b\b\b\b\b\b\bLoading   " << std::flush;
        sleep(1);
        std::cout << "\b\b\b\b\b\b\b\b\b\bLOading   " << std::flush;
        sleep(1);
        std::cout << "\b\b\b\b\b\b\b\b\b\bLoAding   " << std::flush;
        sleep(1);
        std::cout << "\b\b\b\b\b\b\b\b\b\bLoaDing   " << std::flush;
        sleep(1);
        std::cout << "\b\b\b\b\b\b\b\b\b\bLoadIng   " << std::flush;
        sleep(1);
        std::cout << "\b\b\b\b\b\b\b\b\b\bLoadiNg   " << std::flush;
        sleep(1);
        std::cout << "\b\b\b\b\b\b\b\b\b\bLoadinG   " << std::flush;
        sleep(1);
        std::cout << "\b\b\b\b\b\b\b\b\b\bLoading.  " << std::flush;
        sleep(1);
        std::cout << "\b\b\b\b\b\b\b\b\b\bLoading.." << std::flush;
        sleep(1);
        std::cout << "\b\b\b\b\b\b\b\b\b\bLoading..." << std::flush;
        sleep(1);
    }

  if (system ("clear")==-1)
  {
    cout<<"ERROR"<<endl;
  }

  cout << "-================================================================================================-" << endl;
  cout << "" << endl;
  cout<<"  /$$$$$$  /$$   /$$ /$$$$$$$  /$$$$$$  /$$$$$$   /$$$$$$  /$$$$$$$$ /$$$$$$ /$$$$$$$$ /$$     /$$"<<endl;
  cout<<" /$$__  $$| $$  | $$| $$__  $$|_  $$_/ /$$__  $$ /$$__  $$|__  $$__/|_  $$_/|__  $$__/|  $$   /$$/"<<endl;
  cout<<"| $$  \\__/| $$  | $$| $$  \\ $$  | $$  | $$  \\ $$| $$  \\__/   | $$     | $$     | $$    \\  $$ /$$/ "<<endl;
  cout<<"| $$      | $$  | $$| $$$$$$$/  | $$  | $$  | $$|  $$$$$$    | $$     | $$     | $$     \\  $$$$/  "<<endl;
  cout<<"| $$      | $$  | $$| $$__  $$  | $$  | $$  | $$ \\____  $$   | $$     | $$     | $$      \\  $$/   "<<endl;
  cout<<"| $$    $$| $$  | $$| $$  \\ $$  | $$  | $$  | $$ /$$  \\ $$   | $$     | $$     | $$       | $$    "<<endl;
  cout<<"|  $$$$$$/|  $$$$$$/| $$  | $$ /$$$$$$|  $$$$$$/|  $$$$$$/   | $$    /$$$$$$   | $$       | $$    "<<endl;
  cout<<" \\______/  \\______/ |__/  |__/|______/ \\______/  \\______/    |__/   |______/   |__/       |__/    "<<endl;
  cout << "" << endl;
  cout << "-================================================================================================-" << endl;
  cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -- - - - - - - - " << endl;
  cout << "--- - -- - -- - -- - -- -- Bienvenido al sistema del robot CURIOSITY -- - -- - -- - -- - -- - ---" << endl;
  cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -- - - - - - - - " << endl;
  cout << "- - - - - - - - - - - - - - - - Si necesitas ayuda utiliza 'help' - - - - - - - - - - - - - - - -" << endl;
  cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -- - - - - - - - " << endl;
  cout << "=================================================================================================" << endl;
  
  string com;
  
  while(1)
  {
    char str[100];
    cout << "~$";
    cin.getline(str, 100);
    verificarComandos(str);
  }
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
  string buffer;
  ifstream lectura;
  lectura.open("intrucciones.txt",ios::in);
  if(lectura.fail()==true){
    cout << "No se pudo abrir el archivo" << endl;
  }
  else{
    // Aqui van las intrucciones de lectura :)
    cout << "El archivo se abrio exitosamente" <<endl;
  }


  
  lectura.close();
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
  cout << "Simular comandos "<<endl;
}


void shell::enCuadrante()
{
  cout << "enCuadrante"<<endl;
}


void shell::salir()
{
    
}

void shell::ubicarElementos()
{
    
}

void shell::crearMapa()
{
    
}
  
void shell::rutaMasLarga()
{
    
}



