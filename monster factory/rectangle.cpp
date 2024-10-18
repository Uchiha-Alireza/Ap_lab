#include "rectangle.h"
#include <iostream>
Rectangle::Rectangle(const float a1,const float a2):length(a1),height(a2){}
float Rectangle::enviroment()const{
    float enviroment = 2*(length+height);
    return enviroment;
}
float Rectangle::area()const{
    float area = length*height;
    return area;
}
void Rectangle::set_length(float a){
    if(a==0){
        std::cout<<"The number must be greater than zero!"<<std::endl;
    }
    length = a;
}
void Rectangle::set_height(float a){
    if(a!=0)
    {
        std::cout<<"The number must be greater than zero!"<<std::endl;
    }
    height = a;
}
