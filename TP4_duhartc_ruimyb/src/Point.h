//
// Created by ruimyb on 17/03/16.
//

#ifndef TP4_DUHARTC_RUIMYB_POINT_H
#define TP4_DUHARTC_RUIMYB_POINT_H

template<typename T>
class Point {
private:
    float abscice;
    float ordonnee;
public:
    Point(const T a,const T b){
        abscice = a;
        ordonnee = b;
    }
    T x() {
        return abscice;
    }
    T y(){
        return ordonnee;
    }
};



#endif //TP4_DUHARTC_RUIMYB_POINT_H
