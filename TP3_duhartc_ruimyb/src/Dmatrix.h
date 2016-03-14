#ifndef DMATRIX
#define DMATRIX

#include <iostream>
#include <string>
#include "Darray.h"
#include "Dvector.h"

class Dmatrix : public Darray 
{
    private:
        int m; /*nombre de lignes*/
        int n; /*nombre de colonnes*/
    public:
        // on stocke la matrice dans un seul Darray de taille m*n
        Dmatrix();
        ~Dmatrix();
        Dmatrix(int newN, int newM, double optionalInitVal = 0);
        Dmatrix(const Dmatrix & matrix);
        int lines() const;
        int columns() const;
        double & operator () (int i, int j); 
        double operator () (int i, int j) const;
        Dmatrix & operator = (const Dmatrix &Dm);
        Dmatrix & transpose();
        //TODO à enlever
        void display(std::ostream& str) const;
        Dvector line(int pos) const;
        Dvector column(int pos) const;
        Dmatrix & cholesky(); 
};

Dvector operator * (const Dmatrix & Dm, const Dvector & Dv);  
Dmatrix operator * (const Dmatrix & Dm1, const Dmatrix & Dm2); 
#endif
