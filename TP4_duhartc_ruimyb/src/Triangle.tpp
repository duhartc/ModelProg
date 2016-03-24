//
// Created by Ruimy Benjamin Mac on 24/03/2016.
//

template<typename T>
Triangle<T>::Triangle(const Point<T>& A, const Point<T>& B, const Point<T>& C){
    this->P1 = A;
    this->P2 = B;
    this->P3 = C;
}
template<typename T>
    Point<T> Triangle<T>::p1(){
        return this->P1;
    }
template<typename T>
    Point<T> Triangle<T>::p2(){
        return this->P2;
    }
template<typename T>
    Point<T> Triangle<T>::p3(){
        return this->P3;
    }
