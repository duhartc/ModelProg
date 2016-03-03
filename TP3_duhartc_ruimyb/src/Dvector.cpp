
#ifndef DVECTOR
#define DVECTOR

#include <iostream>
#include <string>
#include "Darray.h"

 

class Dvector : public Darray
{
  Dvector();
  Dvector(unsigned int s, double optionalInitVal = 0);
};

#endif
