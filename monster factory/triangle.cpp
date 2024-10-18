#include "triangle.h"
Triangle::Triangle(const float a1,const float a2,const float a3):side1(a1),side2(a2),side3(a3){}
float Triangle::environment()const{
    float enviroment = side1+side2+side3;
    return enviroment;
}
bool Triangle::check_triangle()const{
    if(side1<side2+side3 && side2<side1+side3 && side3<side1+side2){
        return true;
    }
    return false;
}