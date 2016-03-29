//
// Created by Ruimy Benjamin Mac & Duhart Claudia 24/03/2016.
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
    /*!
    *  \brief Constructeur de la classe Triangle
    *
    *  Construction d'un triangle à partir de trois points.
    *
    */
    Triangle(const Point<T>& A, const Point<T>& B, const Point<T>& C);
    /*!
    *  \brief Getteur du premier point du triangle
    *
    *  Méthode permettant de récupérer la valeur de l'attribut P1 de la classe Triangle
    *
    */
    Point<T> p1();

    /*!
    *  \brief Getteur du second point du triangle
    *
    *  Méthode permettant de récupérer la valeur de l'attribut P2 de la classe Triangle
    *
    */
    Point<T> p2();

    /*!
    *  \brief Getteur du second point du triangle
    *
    *  Méthode permettant de récupérer la valeur de l'attribut P3 de la classe Triangle
    *
    */
    Point<T> p3();

    /*!
    *  \brief Methode transformer
    *
    *  Méthode permettant d'effectuer une transformation affine de la classe Triangle
    *
    */
    void transformer( double m11, double m12, double m21, double m22 );

    /*!
    *  \brief Methode deplacer
    *
    *  Méthode permettant d'effectuer une translation de la classe Triangle
    *
    */
    void deplacer( double dx, double dy );

    /*!
    *  \brief Methode tourner
    *
    *  Méthode permettant d'effectuer une rotation par rapport à un point de la classe Triangle
    *
    */
    void tourner( double angle, const Point<T>& pt );

};
template <typename T> std::ostream & operator<<( std::ostream &flux, Triangle<T> t);
#include "Triangle.tpp"

#endif //TP4_DUHARTC_RUIMYB_TRIANGLE_H
