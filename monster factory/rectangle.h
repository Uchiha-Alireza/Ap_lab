#ifndef RECTANGLE_H
#define RECTANGLE_H
class Rectangle{
    private:
    float length;
    float height;
    public:
    Rectangle(const float,const float);
    float enviroment()const;
    float area()const;
    void set_length(float);
    void set_height(float);
};
#endif
