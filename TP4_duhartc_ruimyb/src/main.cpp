#include <iostream>
#include "Point.h"
#include "Triangle.h"
#include "Maillage.h"


int main() {

    typedef double MonType;

    Point<MonType> A(1,2);
    Point<MonType > B(1,2);
    Point<MonType > C(1,2);
    Triangle<MonType > T1(A,B,C);
    std::cout << A.x()<<std::endl;
    std::cout << T1.p1().x()<<std::endl;

    std::cout << "Hello, World!" << std::endl;
    Maillage<MonType, std::vector> m( 1, 1, Point< MonType >(0,0) );
    std::cout << m;
    m.transformer(2,2,2,2);
    m.tourner(3.14/4,Point<MonType>(2,2));
    
    return 0;
}