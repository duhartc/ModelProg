#ifndef DVECTOR
#define DVECTOR
#include <iostream>

class Dvector {
  //private by default
 public: //TODO verif encapsulation 
  unsigned int vsize;
  double *v;
  Dvector();
  Dvector(unsigned int s, double optionalInitVal = 0);
  ~Dvector();
  void display(std::ostream& str);
  int size();
  void fillRandomly();
  Dvector(const Dvector & vect);
};
#endif
