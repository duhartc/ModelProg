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

Dvector::Dvector(const Dvector & vect){}

Dvector::Dvector(const std::string str){}

//Dvector & Dvector::operator = (const Darray &Dv) {
Dvector & Dvector::operator = (const Dvector &Dv) {
    //Darray::operator=(Dv);
    //(Darray)*this = Dv;
    return *this;
}

