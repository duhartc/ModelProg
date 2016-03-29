//
// Created by Ruimy Benjamin & Duhart Claudia on 24/03/2016.
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

template <typename T>
std::ostream & operator<<( std::ostream &flux, Triangle<T> t)
{
    flux << t.p1()  << t.p2() << t.p3() << t.p1();
    return flux;
}


template<typename T>
void Triangle<T>::transformer( double m11, double m12, double m21, double m22 ){
    P1.transformer(m11,m12,m21,m22);
    P2.transformer(m11,m12,m21,m22);
    P3.transformer(m11,m12,m21,m22);
}

template<typename T>
void Triangle<T>::deplacer( double dx, double dy ){
    P1.deplacer(dx,dy);
    P2.deplacer(dx,dy);
    P3.deplacer(dx,dy);
}

template<typename T>
void Triangle<T>::tourner( double angle, const Point<T>& pt ){
    P1.tourner(angle, pt);
    P2.tourner(angle, pt);
    P3.tourner(angle, pt);
}
