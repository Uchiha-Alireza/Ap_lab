#ifndef TRIANGLE_H
#define TRIANGLE_H
class Triangle{
    private:
    float side1;
    float side2;
    float side3;
    public:
    Triangle(const float,const float,const float);
    float environment()const;
    bool check_triangle()const;
};
#endif