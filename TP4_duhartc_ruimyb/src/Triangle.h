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

    void setP1(Point<T> a);

    void setP2(Point<T> a);

    void setP3(Point<T> a);


    void transformer( double m11, double m12, double m21, double m22 );

    void deplacer( double dx, double dy );

    void tourner( double angle, const Point<T>& pt );

};
template <typename T> std::ostream & operator<<( std::ostream &flux, Triangle<T> t);
#include "Triangle.tpp"

#endif //TP4_DUHARTC_RUIMYB_TRIANGLE_H
