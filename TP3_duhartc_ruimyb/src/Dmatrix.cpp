#include "Dmatrix.h"
#include <stdexcept>

Dmatrix::Dmatrix():Darray() {}

Dmatrix::Dmatrix(unsigned int m, unsigned int n, double optionalInitVal):Darray(m*n,optionalInitVal) {
    m = m;
    n = n;
}

Dmatrix::Dmatrix(const Dmatrix & matrix) : Darray(matrix){
    // on passe en Darray en paramètre pour pouvoir contruire un Dvector à partir d'un Darray
    // ainsi, on n'a plus besoin de surcharger l'opérateur d'affectation
    m = matrix.m;
    n = matrix.n;
}

Dmatrix::~Dmatrix() { 
    // rien à faire ici car le déstructeur de Darray est appelé automatiquement
}

int Dmatrix::lines() const{
    return m;
}

int Dmatrix::columns() const{ 
    return n;
}

/*!
 * Operateur d'accession à un élément de la matrice (accès lecture)
 * @param  i retourne une erreur si i n'est pas un indice de la matrice 
 * @param  j retourne une erreur si j n'est pas un indice de la matrice
 */
double & Dmatrix::operator () (int i, int j) {
  if (i < 0 || i >= lines() || j < 0 || j >= columns() ) {
    throw std::logic_error("index out of range");
  }
  return v[j + i*n];
}

/*!
 * Operateur d'accession à un élément de la matrice (accès écriture)
 * @param  i retourne une erreur si i n'est pas un indice de la matrice 
 * @param  j retourne une erreur si j n'est pas un indice de la matrice
 */
double Dmatrix::operator () (int i, int j) const {
  if (i < 0 || i >= size() || j < 0 || j >= columns()) {
    throw std::logic_error("index out of range");
  }
  return v[j + i*n];
}