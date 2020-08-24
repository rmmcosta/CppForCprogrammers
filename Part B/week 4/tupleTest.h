#include <tuple>
#include <iostream>
#ifndef THREE_D
#define THREE_D
class ThreeD
{
private:
    std::tuple<double, double, double> point;

public:
    ThreeD() : point(std::make_tuple(0, 0, 0)) {}
    ThreeD(double x, double y, double z) : point(std::make_tuple(x, y, z)) {}
    friend std::ostream &operator<<(std::ostream &, ThreeD &);
    ThreeD &operator+(ThreeD &);
    ThreeD &operator*(int);
};
#endif