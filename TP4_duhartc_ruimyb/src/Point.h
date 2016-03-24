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
    Point(const T& a, const T& b);

    T x();


    T y();
};

#include "Point.tpp"

#endif //TP4_DUHARTC_RUIMYB_POINT_H