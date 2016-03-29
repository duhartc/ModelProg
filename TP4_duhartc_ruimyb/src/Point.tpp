//
// Created by ruimyb & Duhart Claudia on 17/03/16.
//
#include <cmath>

template<typename T>
Point<T>::Point(const T& a, const T& b){
    this->abscisse = a;
    this->ordonnee = b;
}

template<typename T>
T Point<T>::x() const{
    return this->abscisse;
}

template<typename T>
void Point<T>::setX(T a){
    this->abscisse = a;
}

template<typename T>
T Point<T>::y() const{
    return this->ordonnee;
}

template<typename T>
void Point<T>::setY(T a){
    this->ordonnee = a;
}

template <typename T>
std::ostream & operator<<( std::ostream &flux, Point<T> p){
    flux << p.x() << "  " << p.y() << std::endl;
    return flux;
}
template <typename T>
bool  Point<T>::operator==(const Point<T> &a) const{
    return ( abscisse == a.x() && ordonnee == a.y());
}
template<typename T>
void Point<T>::transformer( double m11, double m12, double m21, double m22 ){
    float a = abscisse;
    float b = ordonnee;
    this->setX(a * m11 + b * m21);
    this->setY(a * m12 + b * m22);
}

template<typename T>
void Point<T>::deplacer( double dx, double dy ){
    this->setX(abscisse + dx);
    this->setY(ordonnee + dy);
}

template<typename T>
void Point<T>::tourner( double angle, const Point<T>& pt ){
    this->setX(abscisse - pt.x());
    this->setY(abscisse - pt.y());
    this->transformer(cos(angle),sin(angle), -sin(angle), cos(angle));
    this->setX(abscisse + pt.x());
    this->setY(abscisse + pt.y());
}
