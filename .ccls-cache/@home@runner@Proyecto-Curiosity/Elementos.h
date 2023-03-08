#ifndef _ELEMENTOS_H_
#define _ELEMENTOS_H_
class Elementos{
private:
  char tipoElemento;
  unsigned long tamanno;
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
  ~Elementos();
};


#endif