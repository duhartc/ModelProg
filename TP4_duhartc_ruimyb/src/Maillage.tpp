//
// Created by Ruimy Benjamin & Duhart Claudia on 24/03/2016.
//
#include <stdexcept>

template <typename T, template <typename = Triangle<T>, typename=std::allocator<Triangle<T> > > class C>

    Maillage<T,C>::Maillage( const Point<T>& p1, const Point<T>& p2, const Point<T>& p3, const Point<T>& p4, int m, int n ){

        if (p1.y() != p2.y() || p1.x() != p4.x() || p4.y() != p3.y() || p3.x() != p2.x()){
            throw std::logic_error("Ce n'est pas un rectangle");
        }else if((p1 == p2 && p3 == p4) || (p1 == p4 && p3 == p2)){
            throw std::logic_error("Le rectangle est plat et ne permet pas de constituer un maillage");
        }

        if (n < 0 || m < 0){
                throw std::logic_error("Maillage inexistant");
        }else {
            mailles = C<Triangle<T> >();
            if (p1 == p2 && p1 == p3 && p1 == p4) {
                origin = p1;
            } else {
                origin = Point<T>(0, 0);
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < n; j++) {
                        //Triangle Inférieur
                        mailles.push_back(Triangle<T>(
                                Point<T>(origin.x() + i, origin.y() + j),
                                Point<T>(origin.x() + i, origin.y() + j + 1),
                                Point<T>(origin.x() + i + 1, origin.y() + j)));
                        //Triangle Supérieur
                        mailles.push_back(Triangle<T>(
                                Point<T>(origin.x() + i + 1, origin.y() + j + 1),
                                Point<T>(origin.x() + i, origin.y() + j + 1),
                                Point<T>(origin.x() + i + 1, origin.y() + j)));
                    }
                }
                transformer((p2.x() - p1.x()) / m, (p2.y() - p1.y()) / m, (p4.x() - p1.x()) / n, (p4.y() - p1.y()) / n);
                deplacer(p1.x(), p1.y());
            }

        }
    }

template <typename T ,template <typename = Triangle<T>, typename = std::allocator<Triangle< T > > > class C>

   Maillage<T,C>::Maillage(int n, int m, const Point<T>& origine){


        mailles = C<Triangle <T> >();
        this->origin = origine;

        //Construction du maillage ( Il convient de créer deux triangles, inférieur et supérieur )

        for (int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                //Triangle Inférieur
                mailles.push_back(Triangle<T>(
                        Point<T>(origin.x() + i, origin.y() + j),
                        Point<T>(origin.x() + i, origin.y() + j + 1),
                        Point<T>(origin.x() + i + 1, origin.y() + j)));
                //Triangle Supérieur
                mailles.push_back(Triangle<T>(
                        Point<T>(origin.x() + i + 1, origin.y() + j + 1),
                        Point<T>(origin.x() + i, origin.y() + j + 1),
                        Point<T>(origin.x() + i + 1, origin.y() + j)));
            }
        }
    }

template <typename T ,template <typename = Triangle<T>, typename = std::allocator<Triangle< T > > > class C>

    typename C<Triangle<T> >::const_iterator Maillage<T,C>::beginiter() const{
        return mailles.begin();
    }

template <typename T ,template <typename = Triangle<T>, typename = std::allocator<Triangle< T > > > class C>

    typename C<Triangle<T> >::const_iterator Maillage<T,C>::enditer() const{
        return mailles.end();
    }


template <typename T ,template <typename = Triangle<T>, typename = std::allocator<Triangle< T > > > class C>
    std::ostream & operator << ( std::ostream &flux, Maillage<T,C> M ){
        typename C<Triangle<T>, std::allocator<Triangle<T> > >::const_iterator it = M.beginiter();
        while(it != M.enditer()){
            flux << *it << std::endl;
            it++;
        }
        return flux;
    }


template <typename T ,template <typename = Triangle<T>, typename = std::allocator<Triangle< T > > > class C>
    void Maillage<T,C>::transformer( double m11, double m12, double m21, double m22 ){
        typename C<Triangle<T>, std::allocator<Triangle<T> > >::iterator it = mailles.begin();
        while(it != mailles.end()){
            it->transformer(m11,m12,m21,m22);
            it++;
        }
        origin.transformer(m11, m12, m21, m22);
    }


template <typename T ,template <typename = Triangle<T>, typename = std::allocator<Triangle< T > > > class C>
    void Maillage<T,C>::deplacer( double dx, double dy ){
        origin.deplacer(dx,dy);
        typename C<Triangle<T>, std::allocator<Triangle<T> > >::iterator it = mailles.begin();
        while(it != mailles.end()){
            it->deplacer(dx,dy);
            it++;
        }

    }

template <typename T ,template <typename = Triangle<T>, typename = std::allocator<Triangle< T > > > class C>
    void Maillage<T,C>::tourner( double angle, const Point<T>& pt ){
        origin.tourner(angle,pt);
        typename C<Triangle<T>, std::allocator<Triangle<T> > >::iterator it = mailles.begin();
        while(it != mailles.end()){
            it->tourner(angle,pt);
            it++;
        }
    }








