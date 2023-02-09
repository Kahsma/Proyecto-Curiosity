#include <iostream>
#include <map>
#include "shell.h"
#include <unistd.h> // for sleep()


using namespace std;
int main(int argc, char *argv[]) 
{
  cout << "Entrada al main" << endl;
  shell *console = new shell();
  console->iniciarShell();
  //console->help();
}