#include "Dvector.h"
#include <cstddef> 
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <sstream>
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

Dvector::Dvector(string str) {
  ifstream file(str.c_str());
  if (!file) {
     //Dvector();
     vsize = 0;
     v = NULL;
  }
  else {
    //on compte le nombre d'éléments
    size_t nbElem = distance(istream_iterator<string>(file), 
                             istream_iterator<string>());

    //unsigned int lines = count( 
    // istreambuf_iterator<char>( file ), 
    //istreambuf_iterator<char>(), 
    // '\n' ); 
    cout << "nombre lignes:" << nbElem <<"fin ligne\n";

    //on crée le vecteur
    vsize = nbElem;
    v = new double[vsize];

    //on retourne au début du fichier
    file.clear();
    file.seekg(0,ios::beg);

    //on insère ces éléments dans le vecteur
    string line;
    stringstream ssConvert;
    double convert;
    string emptyLine = "";
    nbElem = 0;
    while (getline(file, line)) {
      if (emptyLine.compare(line) != 0) {
	ssConvert << line;
	while (ssConvert >> convert) {
	  v[nbElem] = convert;
	  nbElem++;
	}
	ssConvert.clear();
      }
    } 
  }
  file.close();
}
