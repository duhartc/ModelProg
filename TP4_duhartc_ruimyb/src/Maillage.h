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

    typename C<Triangle<T> >::const_iterator beginiter() const;
    typename C<Triangle<T> >::const_iterator enditer() const;
    void transformer( double m11, double m12, double m21, double m22 );
    void deplacer( double dx, double dy );
    void tourner( double angle, const Point<T>& pt );

};

template <typename T ,template <typename = Triangle<T>, typename = std::allocator<Triangle< T > > > class C>
std::ostream & operator << ( std::ostream &flux, Maillage<T,C> M );



#include "Maillage.tpp"

#endif //TP4_DUHARTC_RUIMYB_MAILLAGE_H