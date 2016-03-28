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
template<typename T>
    void Triangle<T>::setP1(Point<T> a){
        this->P1 = a;
    }
template<typename T>
    void Triangle<T>::setP2(Point<T> a){
        this->P2 = a;
    }
template<typename T>
    void Triangle<T>::setP3(Point<T> a){
        this->P3 = a;
    }

template <typename T>
std::ostream & operator<<( std::ostream &flux, Triangle<T> t)
{
    flux << t.p1()  << t.p2() << t.p3() << t.p1();
    return flux;
}


template<typename T>
void Triangle<T>::transformer( double m11, double m12, double m21, double m22 ){
    setP1(p1().transformer(m11,m12,m21,m22));
    setP2(p2().transformer(m11,m12,m21,m22));
    setP3(p3().transformer(m11,m12,m21,m22));
}

template<typename T>
void Triangle<T>::deplacer( double dx, double dy ){
    setP1(p1().deplacer(dx,dy));
    setP2(p2().deplacer(dx,dy));
    setP3(p3().deplacer(dx,dy));
}

template<typename T>
void Triangle<T>::tourner( double angle, const Point<T>& pt ){
    setP1(p1().tourner(angle, pt));
    setP2(p2().tourner(angle, pt));
    setP3(p3().tourner(angle, pt));
}
