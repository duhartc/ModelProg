/*! \file Darray.cpp
 *  \brief     Ensemble des fonctions de la classe Dvector
 *  \author    Claudia Duhart 
 *  \author    Benjamin Ruimy
 *  \version   1.0
 *  \date      2015
 *  \warning   Usage: Dvector
 */

#include "Dvector.h"
#include <stdexcept>


Dvector::Dvector():Darray() {}

Dvector::Dvector(unsigned int s, double optionalInitVal):Darray(s,optionalInitVal) {}

Dvector::Dvector(const Darray & vect) : Darray(vect){
    // on passe en Darray en paramètre pour pouvoir contruire un Dvector à partir d'un Darray
    // ainsi, on n'a plus besoin de surcharger l'opérateur d'affectation
}


Dvector::Dvector(const std::string str):Darray(str){}

Dvector::~Dvector() { 
    // rien à faire ici car le déstructeur de Darray est appelé automatiquement
}

int operator * (const Dvector & Dv1, const Dvector & Dv2) {
    if (Dv1.size() != Dv2.size()) {
        throw std::logic_error("Incompatible sizes");
    }
    int produitSca = 0;
    if (Dv1.size() != 0) {
        for (unsigned int i = 0; i < Dv1.size() ; i++) {
            produitSca += Dv1(i)*Dv2(i);
        }
    }
    return produitSca;
}