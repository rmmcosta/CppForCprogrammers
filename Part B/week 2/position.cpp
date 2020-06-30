#include "position.hpp"

void Position::incX(int a)
{
    x += a;
}

void Position::incY(int a)
{
    y += a;
}

void Position::decX(int a)
{
    x -= a;
}

void Position::decY(int a)
{
    y -= a;
}

ostream &operator<<(ostream &out, Position &p)
{
    out << p.x << ", " << p.y << endl;
    return out;
}