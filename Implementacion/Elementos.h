#ifndef _ELEMENTOS_H_
#define _ELEMENTOS_H_
#include <string>
using namespace std;
class Elementos{
protected:
  char tipoElemento;
  unsigned long tamanno;
  string UnidadMedida;
  float coordX,coordY;
public:
  
  Elementos();
  Elementos(char tipo, unsigned long tam, float x, float y);
  char getTipoElemento() const;
  void setTipoElemento(char tipo);
  unsigned long getTamanno() const;
  void setTamanno(unsigned long tam);
  float getCoordX() const;
  void setCoordX(float x);
  float getCoordY() const;
  void setCoordY(float y);
  string getUnidadMedida();
  void setUnidadMedida(string unidad);
  ~Elementos();
  Elementos& operator = (const Elementos &p ){
  coordX = p.coordX;
  coordY = p.coordY;
  return *this;
  }
  bool operator == (const Elementos &p) const{
  return (coordX == p.coordX && coordY == p.coordY);
  }
  friend std::ostream& operator<<(std::ostream& o, const Elementos& p) {
  o << "(" << p.getCoordX() << "," << p.getCoordY() << ")";
  return o;
  }
};
#include "Elementos.hxx"


#endif