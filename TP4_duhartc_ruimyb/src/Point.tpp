//
// Created by ruimyb on 17/03/16.
//


template<typename T>
Point<T>::Point(const T& a, const T& b){
    this->abscisse = a;
    this->ordonnee = b;
}
template<typename T>
T Point<T>::x() {
    return this->abscisse;
}
template<typename T>
T Point<T>::y(){
    return this->ordonnee;
}

