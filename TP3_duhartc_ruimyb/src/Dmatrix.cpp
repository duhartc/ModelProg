#include "Dmatrix.h"
#include <stdexcept>

Dmatrix::Dmatrix():Darray() {
    m = 0;
    n = 0;
}

Dmatrix::Dmatrix(int newM, int newN, double optionalInitVal):Darray(newM*newN,optionalInitVal) {
    m = newM;
    n = newN;
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

Dvector Dmatrix::line(int pos) const{
    if (pos < 0 || pos >= lines()) {
    throw std::logic_error("index out of range");
  }
    Dvector line(columns());
    for (unsigned int i = 0; i < columns(); i++) {
        line(i) = this->operator()(pos,i);
    }
    return line;
}
        
Dvector Dmatrix::column(int pos) const{
    if (pos < 0 || pos >= columns() ) {
    throw std::logic_error("index out of range");
  }
    Dvector col(lines());
    for (unsigned int i = 0; i < lines(); i++) {
        col(i) = this->operator()(i, pos);
    }
    return col;
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
  return this->Darray::operator()(j + i*n);
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
  return this->Darray::operator()(j + i*n);
}

Dmatrix & Dmatrix::operator = (const Dmatrix &Dm) {
    // TODO : A REVOIR
    if (&Dm != this) {
        m = Dm.lines();
        n = Dm.columns();
        this->Darray::operator=(Dm);
    }
    return *this;
}

Dvector operator * (const Dmatrix & Dm, const Dvector & Dv){
    if (Dv.size() != Dm.columns())
        throw std::logic_error("Incompatible sizes (matrix & vector)");
    Dvector vRes(Dm.lines(), 0);
    for (unsigned int i = 0; i < Dm.lines(); i++){
       for (unsigned int j = 0; j < Dm.columns(); j++){
           //std::cout << "(" << i << "," << j << ") ";
           vRes(i) += Dm(i,j) + Dv(j);
       } 
    }
    return vRes;
    
    
}

Dmatrix operator * (const Dmatrix & Dm1, const Dmatrix & Dm2){
    //TODO vérifier l'implémentation
    if (Dm1.columns() != Dm2.lines())
        throw std::logic_error("Incompatible sizes (matrix & matrix)");
    Dmatrix mRes(Dm1.lines(), Dm2.columns(), 0);
    for (unsigned int i = 0; i < Dm1.lines(); i++){
       for (unsigned int j = 0; j < Dm2.columns(); j++){
           for (unsigned int k = 0; k < Dm1.columns(); k++){
                std::cout << "(" << i << "," << j << "," << k <<") ";
                mRes(i,j) +=  Dm1(i,k) * Dm2(k,j);
           }
       }
    }
    
}

Dmatrix & Dmatrix::transpose(){
    for (unsigned int i = 0; i < lines(); i++){
       for (unsigned int j = 0; j < columns(); j++){
           this->operator()(i,j) = this->Darray::operator()(j*m + i);
       } 
    }
    int temp = m;
    m = columns();
    n = temp;
    return *this;
}


void Dmatrix::display(std::ostream& str) const {
    for (unsigned int i = 0; i < this->lines() ; i++) {
        for (unsigned int j = 0; j < this->columns() ; j++) {
            str << this->operator()(i,j) << " ";
        }
        str << "\n";
    }
}