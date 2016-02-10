/*! \file Dvector.cpp
 *  \brief     Ensemble des fonctions de la classe Dvector
 *  \author    Claudia Duhart 
 *  \author    Benjamin Ruimy
 *  \version   1.0
 *  \date      2015
 *  \warning   Usage: Dvector 
 */

#include "Dvector.h"
#include <cstddef> 
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <stdexcept> 

using namespace std;

/*!
 * Constructeur par défaut de Dvector
 */
Dvector::Dvector() 
{
    cout << "[APPEL AU CONSTRUCTEUR PAR DEFAUT POUR L'OBJET : " << this << endl; 
    vsize = 0;
    v = NULL;
}

/*!
 * Constructeur de Dvector (avec définition de la taille)
 * @param  s taille du vecteur
 * @param  optionalInitVal (optionnel) valeur d'initialisation du vecteur
 */
Dvector::Dvector(unsigned int s, double optionalInitVal) {
    //optionalInitVal = 0 if no value
    cout << "[APPEL AU CONSTRUCTEUR A DEUX PARAMETRES POUR L'OBJET : " << this << " ] " <<endl; 
    vsize = s;
    v = new double[vsize];
    for (unsigned int i = 0; i < vsize ; i++) {
        v[i] = optionalInitVal;
    }
}
/*!
 * Desctructeur de Dvector
 */
Dvector::~Dvector() {
    cout << "[APPEL AU DESTRUCTEUR de l'objet :"<<this<< " ]" << endl; 
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
 * Fonction qui permet d'afficher un Dvector
 * L'affichage se fait avec au minimum deux décimales
 * @param  str flux de sortie
 */
void Dvector::display(ostream& str) const {
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
 * Fonction retournant la taille d'un vecteur
 * \return la taille du vecteur en int
 */
int Dvector::size() const{
    //le int retourné sera non signé 
    return vsize;
}

double randomUniform() {
    rand(); 
    return rand()/(double)RAND_MAX;
}

/*!
 * Fonction qui remplit un Dvector aléatoirement
 */
void Dvector::fillRandomly() {
    srand(time(NULL));
    for (unsigned int i = 0; i < vsize ; i++) {
        v[i] = randomUniform();
    }
}

/*!
 * Constructeur par copie
 * @param  vect référence à un vecteur
 */
Dvector::Dvector(const Dvector &vect) {
    std::cout<<"[APPEL AU CONSTRUCTEUR PAR COPIE POUR L'OBJET : "<<this<<" ]"<<endl;
    vsize = vect.vsize;
    if (vsize==0) return;
    v = new double[vsize];
    for (unsigned int i = 0; i < vsize ; i++) {
        v[i] = vect.v[i]; //copy
    }
} 

/*!
 * Fonction qui crée un vecteur à partir d'un fichier
 * chaque valeur est séparée par un espace ou un retour à la ligne
 * @param  str nom du fichier contenant les valeurs
 */
Dvector::Dvector(const string str) {
    ifstream file(str.c_str());
    if (!file) {
        vsize = 0;
        v = NULL;
    }
    else {
        //on compte le nombre d'éléments
        size_t nbElem = distance(istream_iterator<string>(file), 
                istream_iterator<string>());

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

/*!
 * Operateur d'accession à un élément du vecteur (accès lecture)
 * @param  i retourne une erreur si i n'est pas un indice du vecteur
 */
double & Dvector::operator () (int i) {
  if (i < 0 || i >= size()) {
    throw std::logic_error("i out of range");
  }
  return v[i];
}

/*!
 * Operateur d'accession à un élément du vecteur (accès écriture)
 * @param  i retourne une erreur si i n'est pas un indice du vecteur
 */
double Dvector::operator () (int i) const {
  if (i < 0 || i >= size()) {
    throw std::logic_error("i out of range");
  }
  return v[i];
}

/*!
 * Operateur d'addition/égalité entre 2 vecteurs
 * @param  Dv reference au vecteur de base 
 * \return le vecteur resultant (dans entrée)
 */
Dvector & Dvector::operator += (const Dvector & Dv) {
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
 * Operateur d'addition/égalité entre 1 vecteur et un réel
 * @param x le réel à ajouter 
 * \return le vecteur resultant (dans entrée)
 */
Dvector & Dvector::operator += (double x) {
  //on aurait aussi pu utiliser un constructeur Dvector(size(),x)
  for (int i = 0; i < size(); i++) {
	v[i] += x;
      }
      return *this;
}

/*!
 * Operateur d'addition entre un vecteur et un réel (gauche)
 * @param  Dv reference au vecteur de base 
 * @param  x le double à ajouter
 * \return Un vecteur resultant de l'opération
 */
Dvector operator + (const Dvector & Dv, double x) {
  Dvector vRes(Dv); 
  vRes += x;
  return vRes;
}

/*!
 * Operateur d'addition entre un vecteur et un réel (droite)
 * @param  x le double à ajouter 
 * @param  v reference au vecteur de base
 * \return Un vecteur resultant de l'opération
 */
Dvector operator + (double x, const Dvector & Dv) {
  return Dv + x;
}

/*!
 * Operateur d'addition entre deux vecteurs
 * @param  Dv1 reference au premier vecteur 
 * @param  Dv2 reference au deuxième vecteur
 * \return Un vecteur resultant de l'opération
 */
Dvector operator + (const Dvector & Dv1, const Dvector & Dv2) {
  Dvector vRes(Dv1); 
  vRes += Dv2;
  return vRes;
}

/*!
 * Operateur moins unaire
 * @param  Dv reference au vecteur sur lequel on applique le moins 
 * \return Un vecteur resultant de l'opération
 */
Dvector operator - (const Dvector & Dv) {
  //TODO
}
ostream& operator <<(std::ostream& O, const Dvector & Dv){
  Dv.display(O);
  return O;
}
