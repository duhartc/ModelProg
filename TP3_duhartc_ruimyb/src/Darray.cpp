/*! \file Darray.cpp
 *  \brief     Ensemble des fonctions de la classe Darray
 *  \author    Claudia Duhart 
 *  \author    Benjamin Ruimy
 *  \version   1.0
 *  \date      2015
 *  \warning   Usage: Darray 
 */

#include "Darray.h"
#include <cstddef> 
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <stdexcept> 
#include <cstring>
#include <cmath>
#include <cstdarg>

using namespace std;

/*!
 * Constructeur par défaut de Darray
 */
Darray::Darray() 
{
    cout << "[APPEL AU CONSTRUCTEUR PAR DEFAUT POUR L'OBJET : " << this << endl; 
    vsize = 0;
    v = NULL;
}

/*!
 * Constructeur de Darray (avec définition de la taille)
 * @param  s taille du tableau
 * @param  optionalInitVal (optionnel) valeur d'initialisation du tableau
 */
Darray::Darray(unsigned int s, double optionalInitVal) {
    //optionalInitVal = 0 if no value
    cout << "[APPEL AU CONSTRUCTEUR A DEUX PARAMETRES POUR L'OBJET : " << this << " ] " <<endl; 
    vsize = s;
    if (vsize==0) {
      v = NULL;
    }
    v = new double[vsize];
    for (unsigned int i = 0; i < vsize ; i++) {
        v[i] = optionalInitVal;
    }
}
/*!
 * Desctructeur de Darray
 */
Darray::~Darray() {
    //cout << "[APPEL AU DESTRUCTEUR de l'objet :"<<this<< " ]" << endl; 
    delete [] v;
}

unsigned int nbDecimal(double d){
    string s_dec;
    stringstream ssConvert;
    ssConvert << d;
    ssConvert >> s_dec;
    return(s_dec.substr(s_dec.find(".") + 1).size());
}

/*!
 * Fonction qui permet d'afficher un Darray
 * L'affichage se fait avec au minimum deux décimales
 * @param  str flux de sortie
 */
void Darray::display(ostream& str) const {
    for (unsigned int i = 0; i < vsize ; i++) {
        if (nbDecimal(v[i]) < 2) {
            str << fixed << setprecision(2) << v[i]<<"\n";
        }
        else {
            str << setprecision(nbDecimal(v[i])) << v[i] << "\n";
        }
    }
}

/*!
 * Fonction retournant la taille d'un tableau
 * \return la taille du tableau en int
 */
int Darray::size() const{
    //le int retourné sera non signé 
    return vsize;
}

double randomUniform() {
    rand(); 
    return rand()/(double)RAND_MAX;
}

/*!
 * Fonction qui remplit un Darray aléatoirement
 */
void Darray::fillRandomly() {
    static bool inited = false;
    if (!inited) {
      inited = true;
      srand(time(NULL));
    }
    for (unsigned int i = 0; i < vsize ; i++) {
        v[i] = randomUniform();
    }
}

/*!
 * Constructeur par copie
 * @param  vect référence à un tableau
 */
Darray::Darray(const Darray &vect) {
    std::cout<<"[APPEL AU CONSTRUCTEUR PAR COPIE POUR L'OBJET : "<<this<<" ]"<<endl;
    vsize = vect.vsize;
    if (vsize==0) return;
    v = new double[vsize];
    for (unsigned int i = 0; i < vsize ; i++) {
        v[i] = vect.v[i]; //copy
    }

} 

/*!
 * Fonction qui crée un tableau à partir d'un fichier
 * chaque valeur est séparée par un espace ou un retour à la ligne
 * @param  str nom du fichier contenant les valeurs
 */
Darray::Darray(const string str) {
    ifstream file(str.c_str());
    if (!file) {
        vsize = 0;
        v = NULL;
    }
    else {
        //on compte le nombre d'éléments
        size_t nbElem = distance(istream_iterator<string>(file), 
                istream_iterator<string>());

        //on crée le tableau
        vsize = nbElem;
        v = new double[vsize];

        //on retourne au début du fichier
        file.clear();
        file.seekg(0,ios::beg);

        //on insère ces éléments dans le tableau
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

/*!
 * Operateur d'accession à un élément du tableau (accès lecture)
 * @param  i retourne une erreur si i n'est pas un indice du tableau
 */
double & Darray::operator () (int i) {
  if (i < 0 || i >= size()) {
    throw std::logic_error("i out of range");
  }
  return v[i];
}

/*!
 * Operateur d'accession à un élément du tableau (accès écriture)
 * @param  i retourne une erreur si i n'est pas un indice du tableau
 */
double Darray::operator () (int i) const {
  if (i < 0 || i >= size()) {
    throw std::logic_error("i out of range");
  }
  return v[i];
}

/*!
 * Operateur d'addition/égalité entre 2 tableaux
 * @param  Dv reference au tableau de base 
 * \return le tableau resultant (dans entrée)
 */
Darray & Darray::operator += (const Darray & Dv) {
  if (size() == Dv.size()) {
      for (int i = 0; i < size(); i++) {
	v[i] += Dv(i);
      }
      return *this;
  }
  else {
    throw std::logic_error("Incompatible sizes");
  }
}

/*!
 * Operateur de soustraction/égalité entre 2 tableaux
 * @param  Dv reference au tableau de base 
 * \return le tableau resultant (dans entrée)
 */
Darray & Darray::operator -= (const Darray & Dv) {
  if (size() == Dv.size()) {
      for (int i = 0; i < size(); i++) {
	v[i] -= Dv(i);
      }
      return *this;
  }
  else {
    throw std::logic_error("Incompatible sizes");
  }
}





/*!
 * Operateur d'addition/égalité entre 1 tableau et un réel
 * @param x le réel à ajouter 
 * \return le tableau resultant (dans entrée)
 */
Darray & Darray::operator += (double x) {
  //on aurait aussi pu utiliser un constructeur Darray(size(),x)
  for (int i = 0; i < size(); i++) {
	v[i] += x;
      }
      return *this;
}

/*!
 * Operateur de soustraction/égalité entre 1 tableau et un réel
 * @param x le réel à soustraire
 * \return le tableau resultant (dans entrée)
 */
Darray & Darray::operator -= (double x) {
  for (int i = 0; i < size(); i++) {
	v[i] -= x;
      }
      return *this;
}

/*!
 * Operateur de multiplication/égalité entre 1 tableau et un réel
 * @param x le réel à multiplier
 * \return le tableau resultant (dans entrée)
 */
Darray & Darray::operator *= (double x) {
  for (int i = 0; i < size(); i++) {
	v[i] *= x;
      }
      return *this;
}

/*!
 * Operateur de division/égalité entre 1 tableau et un réel
 * @param x le réel à ajouter 
 * \return le tableau resultant (dans entrée)
 */
Darray & Darray::operator /= (double x) {
  if (x == 0) {
      throw std::logic_error("division by 0");
  }
  for (int i = 0; i < size(); i++) {
	v[i] /= x;
      }
      return *this;
}

/*!
 * Operateur d'addition entre un tableau et un réel (gauche)
 * @param  Dv reference au tableau de base 
 * @param  x le double à ajouter
 * \return Un tableau resultant de l'opération
 */
Darray operator + (const Darray & Dv, double x) {
  Darray vRes(Dv); 
  vRes += x;
  return vRes;
}

/*!
 * Operateur de soustraction entre un tableau et un réel (gauche)
 * @param  Dv reference au tableau de base 
 * @param  x le double à soustraire
 * \return Un tableau resultant de l'opération
 */
Darray operator - (const Darray & Dv, double x) {
  Darray vRes(Dv); 
  vRes -= x;
  return vRes;
}

/*!
 * Operateur de multiplication entre un tableau et un réel (gauche)
 * @param  Dv reference au tableau de base 
 * @param  x le double à soustraire
 * \return Un tableau resultant de l'opération
 */
Darray operator * (const Darray & Dv, double x) {
  Darray vRes(Dv); 
  vRes *= x;
  return vRes;
}

/*!
 * Operateur de division entre un tableau et un réel (gauche)
 * @param  Dv reference au tableau de base 
 * @param  x le double à diviser
 * \return Un tableau resultant de l'opération
 */
Darray operator / (const Darray & Dv, double x) {
  Darray vRes(Dv); 
  if (x == 0) {
    throw std::logic_error("Division by 0"); 
  }
  vRes /= x;
  return vRes;
}

/*!
 * Operateur d'addition entre un tableau et un réel (droite)
 * @param  x le double à ajouter 
 * @param  v reference au tableau de base
 * \return Un tableau resultant de l'opération
 */
Darray operator + (double x, const Darray & Dv) {
  return Dv + x;
}

/*!
 * Operateur de soustraction entre un tableau et un réel (gauche)
 * @param  x le double à multiplier 
 * @param  v reference au tableau de base
 * \return Un tableau resultant de l'opération
 */
Darray operator - (double x, const Darray & Dv) {
  return -Dv + x;
}

/*!
 * Operateur de multiplication entre un tableau et un réel (gauche)
 * @param  x le double à multiplier 
 * @param  v reference au tableau de base
 * \return Un tableau resultant de l'opération
 */
Darray operator * (double x, const Darray & Dv) {
  return Dv * x;
}

/*!
 * Operateur de soustraction entre un tableau et un réel (gauche)
 * @param  x le double à multiplier 
 * @param  v reference au tableau de base
 * \return Un tableau resultant de l'opération
 */
Darray operator / (double x, const Darray & Dv) {
        Darray vRes(Dv.size()); 
      for (int i = 0; i < Dv.size(); i++) {
              if (Dv(i) == 0) {
                      throw std::logic_error("Division by 0"); 
              } 
              vRes(i) = x / Dv(i); 
      }
  return vRes;
}




/*!
 * Operateur d'addition entre deux tableaux
 * @param  Dv1 reference au premier tableau 
 * @param  Dv2 reference au deuxième tableau
 * \return Un tableau resultant de l'opération
 */
Darray operator + (const Darray & Dv1, const Darray & Dv2) {
  Darray vRes(Dv1); 
  vRes += Dv2;
  return vRes;
}

/*!
 * Operateur soustraction entre deux tableaux
 * @param  Dv1 reference au premier tableau 
 * @param  Dv2 reference au deuxième tableau
 * \return Un tableau resultant de l'opération
 */
Darray operator - (const Darray & Dv1, const Darray & Dv2) {
  Darray vRes(Dv1); 
  vRes -= Dv2;
  return vRes;
}




/*!
 * Operateur moins unaire
 * @param  Dv reference au tableau sur lequel on applique le moins 
 * \return Un tableau resultant de l'opération
 */
Darray operator - (const Darray & Dv) {
  Darray vRes(Dv); 
  vRes *= (-1); 
  return vRes;
}

/*!
 * Operateur <<
 * @param  O référence au flux de sortie
 * @param  Dv référence au tableau à retourner 
 * \return un flux de sortie
 */
ostream& operator <<(std::ostream& O, const Darray & Dv){
  Dv.display(O);
  return O;
}

/*!
 * Operateur >>
 * @param  I référence au flux d'entrée
 * @param  Dv référence au tableau à retourner 
 * \return un flux d'entrée
 */
istream& operator >>(std::istream& I, Darray & Dv){
  for (int i=0; i<Dv.size(); i++) {
    I >> Dv(i);
  }
  return I;
}

/*!
 * Operateur d'affectation
 * @param  Dv le tableau à affecter 
 * \return void
 */

Darray & Darray::operator = (const Darray &Dv){
  //Méthode avec memcpy
  if (&Dv != this) {
    unsigned int oldSize = vsize;
    vsize = Dv.size();
    if (vsize == 0) {
      if (oldSize > 0) {
	delete [] v;
      }
      v = NULL;
    }
    else {
      //v = new double[vsize];
      //std::memcpy(v, Dv.v, vsize * sizeof(double));
      Darray DvCopy(Dv);
      std::swap(v, DvCopy.v);
    }
  }
  return *this;
}
/*
 
Darray & Darray::operator = (const Darray &Dv){
  //Méthode avec boucle  
  if (&Dv != this) {
    vsize = Dv.size();
    if (vsize == 0) {
      v = NULL;
    }
    else {
      v = new double[vsize];
      for (unsigned int i = 0; i < vsize ; i++) {
	v[i] = Dv(i);
      }
    }
  }
  return *this;
}
*/

bool compDouble(double x, double y, double precision) {
  if (std::abs(x - y)  < precision) {
    return true;
  }
  return false;
 }

/*!
 * Operateur ==
 * @param  vG référence au tableau de gauche
 * @param  vD référence au tableau de droite 
 * \return booleen
 */
bool operator == (const Darray & vG, const Darray & vD) {
  if (vG.size() != vD.size()){
    return false;
  }
  for (int i = 0; i < vG.size() ; i++) {
    if (!compDouble(vG(i), vD(i), 0.000001)) {
	return false;
      }
  }
  return true;
}

/*!
 * Permet de changer la taille d'un tableau
 * @param  newSize la nouvelle taille du tableau
 * @param  ... paramètres optionnels (double) contenant les nouvelles valeurs
 */
void Darray::resize(unsigned int newSize, ...) {
  //attention, pas de vérification de type
  // mettre explicitement des doubles lors de l'appel
  if (newSize == vsize) {
    return;
  }
  else {
    unsigned int nbArg = newSize - vsize;
    unsigned int oldSize = vsize;
    vsize = newSize;
    if (vsize==0) {
      if (oldSize > 0) {
	delete [] v;
      }
      v = NULL;
    }
    else if (newSize < oldSize) {
      double * newV = new double[vsize];
      //couteux, eventuellement, garder le tableau trop grand en mémoire
      std::memcpy(newV, v, vsize * sizeof(double));
      delete [] v;
      v = newV;
    }
    else {
      double * newV = new double[vsize];
      std::memcpy(newV, v, oldSize * sizeof(double));

      //on ajoute les éléments supplémentaires
      va_list list;
      va_start(list, nbArg);
      for (int arg=0; arg < nbArg; ++arg) {
	newV[oldSize + arg ] = va_arg(list, double);
      }

      delete [] v;
      v = newV;

      va_end(list);
      }
  }
}
