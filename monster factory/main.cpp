#include <iostream>
#include "shapefactory.h"
int main(){
    Triangle* triangle1 = ShapeFactory::createTriangle(3, 4, 5); 
    Triangle* triangle2 = ShapeFactory::createTriangle(1, 2, 3); 
    if(triangle1->check_triangle()==false){
        std::cout<<"Triangle not valid!"<<std::endl;
    }
    else{
        std::cout<<"Triangle valid"<<std::endl;
    }
    if(triangle2->check_triangle()==false){
        std::cout<<"Triangle not valid!"<<std::endl;
    }
    else{
        std::cout<<"Triangle valid"<<std::endl;
    }
    Rectangle* rectangle1 = ShapeFactory::createRectangle(); 
    Rectangle* rectangle2 = ShapeFactory::createRectangle();
    Rectangle* rectangle3 = ShapeFactory::createRectangle();
    rectangle2->set_length(10);
    rectangle2->set_height(10);
    rectangle3->set_length(4); 
    rectangle3->set_height(8);
    std::cout << "Rectangle 1 Area: " << rectangle1->area() << ", enviroment: " << rectangle1->enviroment() << std::endl;
    std::cout << "Rectangle 2 Area: " << rectangle2->area() << ", enviroment: " << rectangle2->enviroment() << std::endl;
    std::cout << "Rectangle 3 Area: " << rectangle3->area() << ", enviroment: " << rectangle3->enviroment() << std::endl;
    Circle* circle = ShapeFactory::createCircle(); 
    std::cout << "Circle Area: " << circle->area() << ", Circumference: " << circle->enviroment() << std::endl;
    std::cout << "Total Triangles Created: " << ShapeFactory::triangleCount() << std::endl;
    std::cout << "Total Rectangles Created: " << ShapeFactory::rectangleCount() << std::endl;
    std::cout << "Total Circles Created: " << ShapeFactory::circleCount() << std::endl;
    delete triangle1;
    delete triangle2;
    delete rectangle1;
    delete rectangle2;
    delete rectangle3;
    delete circle;
    return 0;
}
