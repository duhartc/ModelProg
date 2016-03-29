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
    /*!
    *  \brief Constructeur de la classe Maillage à partir de 4 points
    *
    *  Construction d'un maillage à partir de quatres points, du nombre de segments selon l'horizontale et la verticale
    *
    */
    Maillage( const Point<T>& p1 = Point<T>(0,0),
              const Point<T>& p2 = Point<T>(0,0),
              const Point<T>& p3 = Point<T>(0,0),
              const Point<T>& p4 = Point<T>(0,0),
              int m = 0 ,
              int n = 0);

    /*!
    *  \brief Constructeur de la classe Maillage à partir d'un point d'origine et du nombre de carrés souhaités
    *
    *  Construction d'un maillage à partir d'un point d'origine, puis construction du maillage et fonction du nombre de
    *  mailles carrés souhaités.
    *
    */
    Maillage(int n = 0,
             int m = 0,
             const Point<T>& origin = Point<T>(0,0));

    /*!
    *  \brief Méthode beginiter
    *Permet de récupérer un itérateur constant sur le premier élément du conteneur.
    *
    */
    typename C<Triangle<T> >::const_iterator beginiter() const;

    /*!
    *  \brief Méthode enditer
    *Permet de récupérer un itérateur constant sur le dernier élément du conteneur.
    *
    */
    typename C<Triangle<T> >::const_iterator enditer() const;

    /*!
    *  \brief Methode transformer
    *
    *  Méthode permettant d'effectuer une transformation affine de la classe maillage.
    *
    */
    void transformer( double m11, double m12, double m21, double m22 );

    /*!
    *  \brief Methode deplacer
    *
    *  Méthode permettant d'effectuer une translation de la classe Maillage
    *
    */
    void deplacer( double dx, double dy );

    /*!
    *  \brief Methode tourner
    *
    *  Méthode permettant d'effectuer une rotation par rapport à un point de la classe Maillage
    *
    */
    void tourner( double angle, const Point<T>& pt );

};

template <typename T ,template <typename = Triangle<T>, typename = std::allocator<Triangle< T > > > class C>
std::ostream & operator << ( std::ostream &flux, Maillage<T,C> M );



#include "Maillage.tpp"

#endif //TP4_DUHARTC_RUIMYB_MAILLAGE_H