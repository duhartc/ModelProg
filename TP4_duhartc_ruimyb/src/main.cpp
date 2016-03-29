#include <iostream>
#include "Point.h"
#include "Triangle.h"
#include "Maillage.h"


int main() {

    typedef float MonType;

    Point<MonType> A(1,1);
    Point<MonType > B(1,2);
    Point<MonType > C(1,2);
    Triangle<MonType > T1(A,B,C);

    std::cout << A.x()<<std::endl;
    std::cout << T1.p1().x()<<std::endl;

    Maillage<double, std::vector> m( 1, 1, Point< double >(0.0,0.0) );
    std::cout << m;

    std::cout << "Test transformer OK \n";
    m.transformer(2.1,2,2,2);
    std::cout << m;

    std::cout << "Test deplacer OK \n";
    T1.deplacer(2.2,2.2);
    std::cout << m;

    std::cout << "Test tourner OK \n";
    m.tourner(1.25*3.12,Point<double>(2.2,2.2));
    std::cout << m;


    Maillage<float, std::vector> m1( Point<float>(2,3), Point<float>(7,3), Point<float>(7,6), Point<float>(2,6), 2, 3 );
    std::cout << m1 << "\n YO";

    //Test perf
    //Maillage <double, std::vector> m(1000000,1000000, Point<double>(0,0));

    return 0;
}