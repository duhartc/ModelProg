//
// Created by ruimyb & Duhart Claudia on 17/03/16.
//

#ifndef TP4_DUHARTC_RUIMYB_POINT_H
#define TP4_DUHARTC_RUIMYB_POINT_H

template<typename T>
class Point {
private:
    T abscisse;
    T ordonnee;
public:
    /*!
    *  \brief Constructeur à partir de deux points
    *
    *  Constructeur prenant deux points en paramètres de la classe point.
    *
    */
    Point(const T& a = 0, const T& b = 0);

    /*!
    *  \brief Getteur de l'abscisse
    *
    *  Méthode permettant de récupérer l'attribut abscisse de la classe point
    *
    */
    T x() const;

    /*!
    *  \brief Setteur de l'abscisse
    *
    *  Méthode permettant de modifier la valeur de l'attribut abscisse de la classe point
    *
    */
    void setX(T a);

    /*!
    *  \brief Getteur de l'ordonnee
    *
    *  Méthode permettant de récupérer l'attribut ordonnee de la classe point
    *
    */
    T y() const;


    /*!
    *  \brief Setteur de l'ordonnee
    *
    *  Méthode permettant de modifier la valeur de l'attribut ordonnee de la classe point
    *
    */
    void setY(T a);

    /*!
    *  \brief Methode transformer
    *
    *  Méthode permettant d'effectuer une transformation affine de la classe point
    *
    */
    void transformer( double m11, double m12, double m21, double m22 );


    /*!
    *  \brief Methode deplacer
    *
    *  Méthode permettant d'effectuer une translation de la classe point
    *
    */
    void deplacer( double dx, double dy );

    /*!
    *  \brief Methode tourner
    *
    *  Méthode permettant d'effectuer une rotation autour d'un point de la classe point
    *
    */
    void tourner( double angle, const Point<T>& pt );

    /*!
    *  \brief Operateur ==
    *
    *  Redéfinition de l'opérateur == pour la classe Point.
    *
    */
    bool operator==(const Point<T> &p) const;

};
template<typename T>
std::ostream & operator<<( std::ostream &flux, Point<T> p);


#include "Point.tpp"

#endif //TP4_DUHARTC_RUIMYB_POINT_H