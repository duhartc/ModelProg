//
// Created by Ruimy Benjamin Mac on 24/03/2016.
//

#ifndef TP4_DUHARTC_RUIMYB_TRIANGLE_H
#define TP4_DUHARTC_RUIMYB_TRIANGLE_H


template<typename T>
class Triangle {
private:
    Point<T> P1;
    Point<T> P2;
    Point<T> P3;
public:
    Triangle(const Point<T>& A, const Point<T>& B, const Point<T>& C);

    Point<T> p1();

    Point<T> p2();

    Point<T> p3();
};

#include "Triangle.tpp"

#endif //TP4_DUHARTC_RUIMYB_TRIANGLE_H
