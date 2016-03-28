//
// Created by ruimyb on 17/03/16.
//

#ifndef TP4_DUHARTC_RUIMYB_POINT_H
#define TP4_DUHARTC_RUIMYB_POINT_H

template<typename T>
class Point {
private:
    T abscisse;
    T ordonnee;
public:
    Point(const T& a = 0, const T& b = 0);

    T x() const;

    void setX(T a);

    T y() const;

    void setY(T a);

    Point<T> transformer( double m11, double m12, double m21, double m22 );

    Point<T> deplacer( double dx, double dy );

    Point<T> tourner( double angle, const Point<T>& pt );


};

#include "Point.tpp"

#endif //TP4_DUHARTC_RUIMYB_POINT_H