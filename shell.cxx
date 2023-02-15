//Nombres : Alberto Vigna , Alejandro Salamanca ,Andres Salamanca , Camilo Martinez

#include <iostream>
#include <map>
#include <stdlib.h>
#include "shell.h"
//#include <curses.h>
//#include "conio.h"
#include <unistd.h> // for sleep()
#include <cstring>  
#include <regex>
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

//función para saber que coamndo pasaron 
void shell::verificarComandos(char comm[])
{
  string partido[6];
  char *ptr; // declare a ptr pointer  
  ptr = strtok(comm, " ");
  int i =0;
  partido[i]=ptr;
  while (ptr != NULL)  
    {  
      i++; 
      ptr = strtok (NULL, " "); 
      if(!partido[6].empty()){
        cout<<"demasiados argumentos"<<endl;
        break;
      }
      if(ptr != NULL){
        partido[i]=ptr;
      }
      
    }
  cout<< "el comando fue : "<< partido[0]<<endl;
  if(partido[0].compare("help")==0){
      help();
  }
  else if(partido[0].compare("cargar_comandos")==0){
    
    cargarComandos(partido[1]);
  }
  else if(partido[0].compare("cargar_elementos")==0){
    cargarElementos(partido[1]);
  }
  else if(partido[0].compare( "agregar_movimientos")==0){
    if(partido[1].empty()||partido[2].empty()||partido[3].empty()){
      cout<< "ingrese todos los parametrod"<<endl;
    }
    else{
      try{
        int magnitud = stoi(partido[2]);
        agregarMovimiento(partido[1],magnitud,partido[3]);
      }
      catch(exception &err){
        cout<<"Conversion failure"<<endl;
      }
      
    }
    
  }
  else if(partido[0].compare( "agregar_analisis")==0){
    agregarAnalisis(partido[1],partido[2],partido[3]);
    
  }
  else if(partido[0].compare( "agregar_elementos")==0){
    if(partido[1].empty()||partido[2].empty()||partido[3].empty()||partido[4].empty()||partido[5].empty()){
      cout<< "Ingrese todos los argumentos"<< endl;
    }
    else{
      try{
        int tam = stoi(partido[2]);
        int cordx = stoi(partido[4]);
        int cordy = stoi(partido[5]);
        agregarElemento(partido[1],tam,partido[3],cordx,cordy);
      }
      catch(exception &err){
        cout<<"Conversion failure"<<endl;
      }
      
      
    }
    
  }
  else if(partido[0].compare( "guardar")==0){
    regex regex("(.*?)\\.(txt|csv|CSV|doc|DOC|pdf|PDF)$");
    if(regex_match(partido[1], regex)){
      cout<< "La información ha sido guardada en "<< partido[1]<< endl;
    }
    else{
      cout<< "Error guardando en "<<partido[1] <<endl;
    }
    
  }
  else if(partido[0].compare( "simular_comandos")==0){
    if(partido[1].empty() || partido[2].empty()){
      cout<< "La información requerida no está almacenada en memoria"<<endl;
    }
    else{
      try{
        int cordx = stoi(partido[1]);
        int cordy = stoi(partido[2]);
        simularComandos(cordx,cordy);
      }
      catch(exception &err){
         cout<<"Conversion failure"<<endl;
      }
      
    }
    
    
  }
  else if(partido[0].compare( "en_cuadrante")==0){
    if(partido[4].empty()){
      cout<< "Los elementos no han sido ubicados todavía"<<endl;
    }else{
      try{
        int corx1=stoi(partido[1]);
        int corx2=stoi(partido[2]);
        int cory1=stoi(partido[3]);
        int cory2=stoi(partido[4]);
        enCuadrante(corx1,corx2,cory1,cory2);
      }
      catch(exception &err){
         cout<<"Conversion failure"<<endl;
      }
      
    } 
  }
  else if(partido[0].compare("salir")==0){
    salir();    
  }
  else if(partido[0].compare("ubicar_elementos")==0){
    ubicarElementos();
    
  }
  else if(partido[0].compare("crear_mapa")==0){
    crearMapa();
  }
  else if(partido[0].compare("ruta_mas_larga")==0){
    rutaMasLarga();
  }
}

// Funcion de inicializacion.
void shell::iniciarShell()
{
  //Borrar consola
  //if (system ("CLS")==-1)
  //{
   // cout<<"ERROR"<<endl;
  //}
  limpiar();
  cout << "Cargando, por favor espere..." << endl;
  cout << '-' << flush;
    for (int i = 0; i < 1; i++ ) 
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

  //if (system ("CLS")==-1)
  //{
   // cout<<"ERROR"<<endl;
  //}
  limpiar();
  cout << "-================================================================================================-" << endl;
  cout << "" << endl;
  cout<<"      /$$$$$$  /$$   /$$ /$$$$$$$  /$$$$$$  /$$$$$$   /$$$$$$  /$$$$$$ /$$$$$$$$ /$$     /$$"<<endl;
  cout<<"     /$$__  $$| $$  | $$| $$__  $$|_  $$_/ /$$__  $$ /$$__  $$|_  $$_/|__  $$__/|  $$   /$$/"<<endl;
  cout<<"    | $$  \\__/| $$  | $$| $$  \\ $$  | $$  | $$  \\ $$| $$  \\__/  | $$     | $$    \\  $$ /$$/ "<<endl;
  cout<<"    | $$      | $$  | $$| $$$$$$$/  | $$  | $$  | $$|  $$$$$$   | $$     | $$     \\  $$$$/  "<<endl;
  cout<<"    | $$      | $$  | $$| $$__  $$  | $$  | $$  | $$ \\____  $$  | $$     | $$      \\  $$/   "<<endl;
  cout<<"    | $$    $$| $$  | $$| $$  \\ $$  | $$  | $$  | $$ /$$  \\ $$  | $$     | $$       | $$    "<<endl;
  cout<<"    |  $$$$$$/|  $$$$$$/| $$  | $$ /$$$$$$|  $$$$$$/|  $$$$$$/ /$$$$$$   | $$       | $$   "<<endl;
  cout<<"     \\______/  \\______/ |__/  |__/|______/ \\______/  \\______/ |______/   |__/       |__/   "<<endl;
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
    //cin.ignore();
    verificarComandos(str);
  }
}




// Funcion de cargar comandos.
void shell::cargarComandos(string nombre)
{
  cout << "Cargar comandos." << endl;

  string buffer;
  ifstream lectura;
  //string nombre = "instrucciones.txt";
  regex regex("(.*?)\\.(txt)$");
  if(regex_match(nombre, regex)){
      cout<< "Archivo valido ."<< endl;
  }
  else{
      cout<< "nombre_archivo no se encuentra o no puede leerse."<<endl;
  }
  lectura.open("intrucciones.txt",ios::in);
  bool isEmpty = lectura.peek() == EOF;
  if(lectura.fail()==true){
    cout << "No se pudo abrir el archivo " + nombre << endl;
  }
  if(isEmpty){
    cout <<"El archivo " + nombre +" esta vacio";
  }
    
  else{
    // Aqui van las intrucciones de lectura :)
    cout << "El archivo: " + nombre + " se abrio exitosamente" <<endl;
  }


  
  lectura.close();
}


// Funcion de cargar elementos.
void shell::cargarElementos(string nombre )
{
  string buffer;
  ifstream lectura;
  //nombre = "instrucciones.txt";
  regex regex("(.*?)\\.(txt)$");
  if(regex_match(nombre, regex)){
      cout<< "archivo valido ."<< endl;
  }
  else{
      cout<< "nombre_archivo no se encuentra o no puede leerse."<<endl;
  }
  lectura.open(nombre,ios::in);
  bool isEmpty = lectura.peek() == EOF;
  if(lectura.fail()==true){
    cout << "No se pudo abrir el archivo " + nombre << endl;
  }
  if(isEmpty){
    cout <<"El archivo " + nombre +" esta vacio";
  }
    
  else{
    // Aqui van las intrucciones de lectura :)
    cout << "El archivo: " + nombre + " se abrio exitosamente" <<endl;
  }


  
  lectura.close();
}


// Funcion de agregar movimiento.
void shell::agregarMovimiento(string tipo,int magnitud,string unidad)
{
  //cout << "Agregar movimiento." << endl;
  //cout << tipo<< magnitud<< unidad<<endl;
  if(!(tipo.compare("avanzar")==0 ||tipo.compare("girar")==0 )){
    cout<< "La información del movimiento no corresponde a los datos esperados(tipo, magnitud, unidad)"<<endl;
    return;
  }
  if(magnitud<0){
    cout<< "La información del movimiento no corresponde a los datos esperados(tipo, magnitud, unidad)"<<endl;
    return;
  }
}


// Funcion de agregar analisis. 
void shell::agregarAnalisis(string tipo,string objteo, string comentario)
{
  if(!(tipo.compare("fotografiar")==0 ||tipo.compare("composicion")==0 ||tipo.compare("perforar")==0 )){
    cout<< "La información del análisis no corresponde a los datos esperados (tipo,objeto, comentario)"<<endl;
    return;
  }
  cout << tipo << objteo<< comentario <<endl;
}


// Funcion de agregar elementos.
void shell::agregarElemento(string tipoComp , int tamanio,string unidadMedida,int cordx,int cordy)
{
  if(tipoComp.compare("roca")==0||tipoComp.compare("crater")==0||tipoComp.compare("monticulo")==0||tipoComp.compare("duna")==0){
    cout<< "La información del elemento no corresponde a los datos esperados (tipo,tamaño, unidad,x,y)"<<endl;
    return;
  }
  if(tamanio<0){
    cout<< "La información del elemento no corresponde a los datos esperados (tipo,tamaño, unidad,x,y)"<<endl;
    return;
  }
  
  cout << "El elemento ha sido agregado exitosamente." << endl;
  
}


void shell::guardar()
{
  cout<< "funcion guardar"<<endl;
}


void shell::simularComandos(int x,int y)
{
  cout << "La simulación de los comandos, a partir de la posición (coordX,coordY ), "<<endl;
}


void shell::enCuadrante(int x1,int x2,int y1,int y2)
{
  cout << "enCuadrante"<<endl;
  cout << "Los elementos ubicados en el cuadrante solicitado son: "<<x1<< x2<<y1 << y2<<endl;
}


void shell::salir()
{
  
    exit(0);
}

void shell::ubicarElementos()
{
    cout << "Funcion Elementos"<<endl;
}

void shell::crearMapa()
{
    cout << "Funcion crear Mapa"<<endl;
}
  
void shell::rutaMasLarga()
{
    cout << "Funcion ruta Mas Larga"<<endl;
}
void shell::limpiar(){
  #if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
  if (system ("CLS")==-1)
    {
      cout<<"ERROR"<<endl;
    }
   //define something for Windows (32-bit and 64-bit, this part is common)
   #ifdef _WIN64
    if (system ("CLS")==-1)
    {
      cout<<"ERROR"<<endl;
    }
      //define something for Windows (64-bit only)
   #else
    if (system ("CLS")==-1)
    {
      cout<<"ERROR"<<endl;
    }
      //define something for Windows (32-bit only)
   #endif
#elif __APPLE__
    #include <TargetConditionals.h>
    if (system ("clear")==-1)
    {
      cout<<"ERROR"<<endl;
    }
    #endif
#elif __ANDROID__
    // Below __linux__ check should be enough to handle Android,
    // but something may be unique to Android.
#elif __linux__
  if (system ("clear")==-1)
    {
      cout<<"ERROR"<<endl;
    }
    // linux
#elif __unix__ // all unices not caught above
    // Unix
#elif defined(_POSIX_VERSION)
    // POSIX
#else
#   error "Unknown compiler"
#endif
}




