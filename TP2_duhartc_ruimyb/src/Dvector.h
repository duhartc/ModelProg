#ifndef DVECTOR
#define DVECTOR
#include <iostream>
#include <string>

class Dvector {
  //private by default
  unsigned int vsize;
  double *v;
 public:  
  Dvector();
  Dvector(unsigned int s, double optionalInitVal = 0);
  ~Dvector();
  void display(std::ostream& str) const;
  int size() const;
  void fillRandomly();
  Dvector(const Dvector & vect);
  Dvector(const std::string str);
  double & operator () (int i); 
  double operator () (int i) const;
  Dvector & operator += (const Dvector & Dv);
  Dvector & operator += (const double x);
}; 

Dvector operator + (const Dvector & Dv, const double x); 
Dvector operator + (const double x, const Dvector & Dv);
#endif
