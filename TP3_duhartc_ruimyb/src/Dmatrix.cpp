/*! \file Darray.cpp
 *  \brief     Ensemble des fonctions de la classe Dmatrix
 *  \author    Claudia Duhart 
 *  \author    Benjamin Ruimy
 *  \version   1.0
 *  \date      2015
 *  \warning   Usage: Dmatrix 
 */
#include "Dmatrix.h"
#include <stdexcept>
#include <cmath> 

/*!
 * Constructeur par défaut de Dmatrix
 */
Dmatrix::Dmatrix():Darray() {
    m = 0;
    n = 0;
}

/*!
 * Constructeur de Dmatrix (avec définition de la taille)
 * @param  s taille du tableau
 * @param  optionalInitVal (optionnel) valeur d'initialisation du tableau
 */
Dmatrix::Dmatrix(int newM, int newN, double optionalInitVal):Darray(newM*newN,optionalInitVal) {
    m = newM;
    n = newN;
}

/*!
 * Constructeur par copie de Dmatrix
 * @param  matrix Dmatrix à copier
 */
Dmatrix::Dmatrix(const Dmatrix & matrix) : Darray(matrix){
    // on passe en Darray en paramètre pour pouvoir contruire un Dvector à partir d'un Darray
    // ainsi, on n'a plus besoin de surcharger l'opérateur d'affectation
    m = matrix.m;
    n = matrix.n;
}

/*!
 * Desctructeur de Dmatrix
 */
Dmatrix::~Dmatrix() { 
    // rien à faire ici car le déstructeur de Darray est appelé automatiquement
}

/*!
 * Nombre de ligne
 * \return Retourne le nombre de ligne de la matrice
 */
int Dmatrix::lines() const{
    return m;
}

/*!
 * Nombre de colonne
 * \return Retourne le nombre de colonne de la matrice
 */
int Dmatrix::columns() const{ 
    return n;
}

/*!
 * Extraction d'une ligne
 * @param  pos position de la ligne à extraire 
 * \return Retourne un Dvector correspondant à la ligne extraite
 */
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

/*!
 * Extraction d'une colonne
 * @param  pos position de la colonne à extraire 
 * \return Retourne un Dvector correspondant à la colonne extraite
 */
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

/*!
 * Operateur d'affectation
 * @param  Dm référence vers la matrice à retourner 
 * \return Retourne un pointeur vers la matrice courante
 */
Dmatrix & Dmatrix::operator = (const Dmatrix &Dm) {
    if (&Dm != this) {
        m = Dm.lines();
        n = Dm.columns();
        this->Darray::operator=(Dm);
    }
    return *this;
}

/*!
 * Operateur de multiplication entre une matrice et un vecteur
 * @param  Dm reference à la matrice
 * @param  Dv référence au vecteur
 * \return Un vecteur resultant de l'opération
 */
Dvector operator * (const Dmatrix & Dm, const Dvector & Dv){
    if (Dv.size() != Dm.columns())
        throw std::logic_error("Incompatible sizes (matrix & vector)");
    Dvector vRes(Dm.lines(), 0);
    for (unsigned int i = 0; i < Dm.lines(); i++){
       for (unsigned int j = 0; j < Dm.columns(); j++){
           vRes(i) += Dm(i,j) + Dv(j);
       } 
    }
    
    return vRes;
    
    
}

/*!
 * Operateur de multiplication entre deux matrices
 * @param  Dm1 reference à la premiere matrice
 * @param  Dm2 reference à la deuxième matrice
 * \return Une matrice resultant de l'opération
 */
Dmatrix operator * (const Dmatrix & Dm1, const Dmatrix & Dm2){
    if (Dm1.columns() != Dm2.lines())
        throw std::logic_error("Incompatible sizes (matrix & matrix)");
    Dmatrix mRes(Dm1.lines(), Dm2.columns(), 0);
    for (unsigned int i = 0; i < Dm1.lines(); i++){
       for (unsigned int j = 0; j < Dm2.columns(); j++){
           for (unsigned int k = 0; k < Dm1.columns(); k++){
                mRes(i,j) +=  Dm1(i,k) * Dm2(k,j);
           }
       }
    }
    return mRes;
}

/*!
 * Permet de transposer la matrice courante (chainable)
 * \return pointeur sur la matrice résultante
 */
Dmatrix & Dmatrix::transpose(){
    Dmatrix temp2(n,m); 
    
    for (unsigned int i = 0; i < lines(); i++){
       for (unsigned int j = 0; j < columns(); j++){
            temp2(j,i) = this->operator()(i,j); 
       } 
    }
    *this = temp2;
    return *this;
}

/*!
 * Permet d'appliquer Cholesky sur la matrice courante 
 * \return pointeur sur la matrice résultante
 */
Dmatrix & Dmatrix::cholesky(){
    if(m != n){
        throw std::logic_error("La matrice n'est pas carrée"); 
    }
    //Il faudrait faire un test pour savoir si la matrice en entrée est bien symétrique/définie/positive
    //pour ne pas perdre de temps 
    Dmatrix L(lines(),lines(),0); 
    double res; 
    for (int k = 0; k < lines(); k++){
        res = 0;
        for(int s = 0; s < k;s++){
            res = res + L(k,s) * L(k,s);      
        }
        std::cout << this->operator()(k,k)-res; 
        L(k,k) = sqrt(this->operator()(k,k) - res);
        for(int i = k+1; i < lines(); i++){
            //std::cout <<"(" <<  i << ","<< k << ")";
            res = 0; 
            for(int s = 0; i < k - 1; s++){

            res = res + L(i,s)*L(k,s); 
            }
            L(i,k) = (this->operator()(i,k) - res) / L(k,k);  
        }
    }
    *this = L; 
   return *this;  
}

/*!
 * Fonction qui permet d'afficher une Dmatrix
 * @param  str flux de sortie
 */
void Dmatrix::display(std::ostream& str) const {
    for (unsigned int i = 0; i < this->lines() ; i++) {
        for (unsigned int j = 0; j < this->columns() ; j++) {
            str << this->operator()(i,j) << " ";
        }
        str << "\n";
    }
}
