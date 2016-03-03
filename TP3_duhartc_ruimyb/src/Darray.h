#ifndef DARRAY
#define DARRAY
#include <iostream>
#include <string>

class Darray {
  //private by default
  unsigned int vsize;
  double *v;
 public:  
  Darray();
  Darray(unsigned int s, double optionalInitVal = 0);
  ~Darray();
  void display(std::ostream& str) const;
  int size() const;
  void fillRandomly();
  Darray(const Darray & vect);
  Darray(const std::string str);
  double & operator () (int i); 
  double operator () (int i) const;
  Darray & operator += (const Darray & Dv);
  Darray & operator += (const double x);
  Darray & operator -= (const Darray & Dv);
  Darray & operator -= (const double x);
  Darray & operator *= (const double x);
  Darray & operator /= (const double x);
  Darray & operator = (const Darray &Dv);
  void resize(unsigned int newSize, ...);

}; 

Darray operator + (const Darray & Dv, const double x); 
Darray operator + (const double x, const Darray & Dv);
Darray operator + (const Darray & Dv1, const Darray & Dv2);

Darray operator - (const Darray & Dv, const double x); 
Darray operator - (const double x, const Darray & Dv);
Darray operator - (const Darray & Dv1, const Darray & Dv2);

Darray operator * (const Darray & Dv, const double x); 
Darray operator * (const double x, const Darray & Dv);

Darray operator / (const Darray & Dv, const double x); 
Darray operator / (const double x, const Darray & Dv);

Darray operator - (const Darray & Dv); //moins unaire

std::ostream& operator <<(std::ostream& O, const Darray & Dv);
std::istream& operator >>(std::istream& I, Darray & Dv);

bool operator == (const Darray & vG, const Darray & vD);
#endif
