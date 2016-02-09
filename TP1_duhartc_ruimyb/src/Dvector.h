#ifndef DVECTOR
#define DVECTOR
#include <iostream>
#include <string>

class Dvector {
  //private by default
  unsigned int vsize;
  double *v;
 public: //TODO verif encapsulation 
  Dvector();
  Dvector(unsigned int s, double optionalInitVal = 0);
  ~Dvector();
  void display(std::ostream& str) const;
  int size() const;
  void fillRandomly();
  Dvector(const Dvector & vect);
  Dvector(const std::string str);
};
#endif
