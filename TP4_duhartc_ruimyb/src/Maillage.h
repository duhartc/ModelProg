//
// Created by Ruimy Benjamin Mac on 24/03/2016.
//
#include "Point.h"
#include <vector>
#include "Triangle.h"

#ifndef TP4_DUHARTC_RUIMYB_MAILLAGE_H
#define TP4_DUHARTC_RUIMYB_MAILLAGE_H


template <typename T ,template <typename = Triangle<T>, typename = std::allocator<Triangle< T > > > class C>
class Maillage {
private:
    C<> mailles;
    Point<T> origin;
public:
    Maillage(int n, int m, const Point<T>& origin);

    //typename C<Triangle<T>, std::allocator<Triangle<T> > >::const_iterator beginiter();

    //typename C<Triangle<T>, std::allocator<Triangle<T> > >::const_iterator endiniter();

};

#include "Maillage.tpp"

#endif //TP4_DUHARTC_RUIMYB_MAILLAGE_H
