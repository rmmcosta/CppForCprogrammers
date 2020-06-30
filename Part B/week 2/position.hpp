#include <iostream>
using namespace std;

#ifndef POSITION_HPP
#define POSITION_HPP
class Position
{
public:
    Position(int x = 0, int y = 0) : x(x), y(y) {}
    void incX(int);
    void incY(int);
    void decX(int);
    void decY(int);
    friend ostream &operator<<(ostream &, Position &);

private:
    int x, y;
};
#endif