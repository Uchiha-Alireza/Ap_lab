#ifndef SHAPEFACTORY_H
#define SHAPEFACTORY_H
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"
class ShapeFactory {
    private:
    static int triangle;
    static int rectangle;
    static int circle;
    ShapeFactory() {}
    ShapeFactory(const ShapeFactory&) = delete;
    ShapeFactory& operator=(const ShapeFactory&) = delete;
    public:
    static Triangle* createTriangle(float, float, float);
    static Rectangle* createRectangle();
    static Circle* createCircle();
    static int triangleCount();   
    static int rectangleCount();   
    static int circleCount();
};

#endif
