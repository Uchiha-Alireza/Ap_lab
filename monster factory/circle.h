#ifndef CIRCLE_H
#define CIRCLE_H
class Circle{
    private:
    float radius;
    public:
    static constexpr float PI=3.141;
    Circle(const float);
    float area()const;
    float enviroment()const;
};
#endif 