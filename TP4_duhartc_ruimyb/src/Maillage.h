//
// Created by Ruimy Benjamin & Duhart Claudia on 24/03/2016.
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

    Maillage( const Point<T>& p1 = Point<T>(0,0),
              const Point<T>& p2 = Point<T>(0,0),
              const Point<T>& p3 = Point<T>(0,0),
              const Point<T>& p4 = Point<T>(0,0),
              int m = 0 ,
              int n = 0);

    Maillage(int n = 0,
             int m = 0,
             const Point<T>& origin = Point<T>(0,0));

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