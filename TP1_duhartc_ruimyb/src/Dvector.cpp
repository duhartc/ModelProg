#include "Dvector.h"
#include <cstddef> 
using namespace std;

Dvector::Dvector() 
{
  size = 0;
  v = NULL;
}
Dvector::Dvector(unsigned int s, double optionalInitVal) {
  //optionalInitVal = 0 if no value
  size = s;
  v = new double[size];
  for (unsigned int i = 0; i < size ; i++) {
    v[i] = optionalInitVal;
  }
}
Dvector::~Dvector() {
  delete [] v;
}

void Dvector::display(ostream& str) {
  for (unsigned int i = 0; i < size ; i++) {
    str<<v[i]<<"\n";
  }
}

