#ifndef SIMPLE_HPP
#define SIMPLE_HPP
class Simple
{
public:
    Simple() = default; //compiler generated
    Simple(int x, int y) : x(x), y(y) {}
    Simple(double, double) = delete;              //supressed conversion constructor
    Simple(int x) : Simple(x, 1) {}               //delegate constructor
    Simple(double) = delete;                      //supressed conversion constructor
    Simple(const Simple &s) : Simple(s.x, s.y) {} //copy constructor with delegate constructor
    Simple(Simple &&s) : Simple(s.x, s.y)
    {
        s.x = 0;
        s.y = 0;
    }
    void print();
    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }

private:
    int x = 0, y = 1;
};

class Rational : public Simple
{
public:
    using Simple::Simple;//implicitly declares constructors
};
#endif