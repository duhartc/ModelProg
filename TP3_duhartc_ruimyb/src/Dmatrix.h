#ifndef DMATRIX
#define DMATRIX

#include <iostream>
#include <string>
#include "Darray.h"

class Dmatrix : public Darray 
{
    private:
        int m; /*nombre de lignes*/
        int n; /*nombre de colonnes*/
    public:
        // on stocke la matrice dans un seul Darray de taille m*n
        Dmatrix();
        ~Dmatrix();
        Dmatrix(unsigned int m, unsigned int n, double optionalInitVal = 0);
        Dmatrix(const Darray & vect);
        int lines() const;
        int columns() const;
        double & operator () (int i, int j); 
        double operator () (int i, int j) const;
};
#endif