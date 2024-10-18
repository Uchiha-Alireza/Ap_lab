#include "circle.h"
Circle::Circle(float a):radius(a){}
float Circle::area()const{
    float area = PI * radius *radius;
    return area;
}
float Circle::enviroment()const{
    float enviroment = 2 * PI * radius;
    return enviroment;
}
