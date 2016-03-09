#ifndef DVECTOR
#define DVECTOR

#include <iostream>
#include <string>
#include "Darray.h"
 

class Dvector : public Darray
{
    public :
  Dvector();
  Dvector(unsigned int s, double optionalInitVal = 0);
  Dvector(const Dvector & vect);
  Dvector(const std::string str);
  Dvector & operator = (const Dvector &Dv);
};

#endif
