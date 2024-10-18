#include "shapefactory.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"
#include <sys/stat.h>
int ShapeFactory::triangle = 0;
int ShapeFactory::rectangle = 0;
int ShapeFactory::circle = 0;
Triangle* ShapeFactory::createTriangle(float a, float b, float c) {
    triangle++; 
    return new Triangle(a, b, c); 
}
Rectangle* ShapeFactory::createRectangle(){
    rectangle++;
    return new Rectangle(10,5);
}
Circle* ShapeFactory::createCircle(){
    circle++;
    return new Circle(5);
}
int ShapeFactory::triangleCount(){
    return triangle;
}   
int ShapeFactory::rectangleCount(){
    return rectangle;
}   
int ShapeFactory::circleCount(){
    return circle;
}
