#include <iostream>
#include "Point.h"
#include "Triangle.h"


int main() {
    Point<float> A(1,2);
    Point<float> B(1,2);
    Point<float> C(1,2);
    Triangle<float> T1(A,B,C);
    std::cout << A.x();
    std::cout << "Hello, World!" << std::endl;

    return 0;
}