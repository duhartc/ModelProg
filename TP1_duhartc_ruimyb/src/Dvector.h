#ifndef DVECTOR
#define DVECTOR
#include <iostream>
class Dvector {
  double *v; //private by default
 public:
  unsigned int size;
  Dvector();
  Dvector(unsigned int s, double optionalInitVal = 0);
  ~Dvector();
  void display(std::ostream& str);
};
#endif
