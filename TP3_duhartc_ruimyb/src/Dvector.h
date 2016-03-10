#ifndef DVECTOR
#define DVECTOR

#include <iostream>
#include <string>
#include "Darray.h"
 

class Dvector : public Darray
{
    public :
  Dvector();
  ~Dvector();
  Dvector(unsigned int s, double optionalInitVal = 0);
  Dvector(const Darray & vect);
  Dvector(const std::string str);
};

int operator * (const Dvector & Dv1, const Dvector & Dv2);

#endif
