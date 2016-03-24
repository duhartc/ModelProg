//
// Created by Ruimy Benjamin Mac on 24/03/2016.
//



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
                        Point<T>(origin.x() + i + 1, origin.y() + j + 1)));
                //Triangle Supérieur
                mailles.push_back(Triangle<T>(
                        Point<T>(origin.x() + i, origin.y() + j),
                        Point<T>(origin.x() + i + 1, origin.y() + j),
                        Point<T>(origin.x() + i + 1, origin.y() + j + 1)));
            }
        }
    }

template <typename T ,template <typename = Triangle<T>, typename = std::allocator<Triangle< T > > > class C>

    typename C<Triangle<T> >::const_iterator beginiter() {
        return Maillage<T,C>::mailles.begin();
    }

template <typename T ,template <typename = Triangle<T>, typename = std::allocator<Triangle< T > > > class C>

    typename C<Triangle<T> >::const_iterator enditer() {
        return Maillage<T,C>::mailles.end();
    }






