#include "Dvector.h"
#include <cstddef> 
#include <cstdlib>
#include <ctime>
using namespace std;

Dvector::Dvector() 
{
  vsize = 0;
  v = NULL;
}

Dvector::Dvector(unsigned int s, double optionalInitVal) {
  cout<<"ici";
  //optionalInitVal = 0 if no value
  //TODO vérif valeur de s ? pas si unsigned
  vsize = s;
  cout<<"ici "<<vsize<<"vs\n";
  v = new double[vsize];
  for (unsigned int i = 0; i < vsize ; i++) {
    v[i] = optionalInitVal;
  }
}

Dvector::~Dvector() {
  delete [] v;
}

void Dvector::display(ostream& str) {
  for (unsigned int i = 0; i < vsize ; i++) {
    //TODO affichage 2 décimales
    str<<v[i]<<"\n";
  }
}

int Dvector::size() {
  //le int retourné sera non signé
  //TODO vérif si unsigned int ou int 
  return vsize;
}

double randomUniform() {
  //srand(time(NULL));
  //retourne toujours la meme séquence pour l'instant
  return rand()/(double)RAND_MAX;
}
void Dvector::fillRandomly() {
  for (unsigned int i = 0; i < vsize ; i++) {
    v[i] = randomUniform();
  }
}

Dvector::Dvector(const Dvector &vect) {
  std::cout<<"copy";
  vsize = vect.vsize;
  if (vsize==0) return;
  v = new double[vsize];
  for (unsigned int i = 0; i < vsize ; i++) {
    v[i] = vect.v[i]; //copy
  }
} 
