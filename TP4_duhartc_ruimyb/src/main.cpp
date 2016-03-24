#include <iostream>
#include "Point.h"
#include "Triangle.h"
#include "Maillage.h"


int main() {

    typedef float MonType;

    Point<MonType> A(1,2);
    Point<MonType > B(1,2);
    Point<MonType > C(1,2);
    Triangle<MonType > T1(A,B,C);
    std::cout << A.x()<<std::endl;
    std::cout << T1.p1().x()<<std::endl;

   // Maillage<MonType,std::vector>()
    std::cout << "Hello, World!" << std::endl;

    return 0;
}