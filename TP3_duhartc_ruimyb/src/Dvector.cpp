/*! \file Darray.cpp
 *  \brief     Ensemble des fonctions de la classe Dvector
 *  \author    Claudia Duhart 
 *  \author    Benjamin Ruimy
 *  \version   1.0
 *  \date      2015
 *  \warning   Usage: Dvector
 */

#include "Dvector.h"


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
