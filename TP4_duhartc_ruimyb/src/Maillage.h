//
// Created by Ruimy Benjamin Mac on 24/03/2016.
//
#include "Point.h"
#ifndef TP4_DUHARTC_RUIMYB_MAILLAGE_H
#define TP4_DUHARTC_RUIMYB_MAILLAGE_H

template<typename T>
template<typename C>
class Maillage {
private:
    int m;
    int n;
    Point<T> origin;
public:
    Maillage<T,C>(int n, int m, const Point<T>& origin);

};

#include "Maillage.tpp"

#endif //TP4_DUHARTC_RUIMYB_MAILLAGE_H
