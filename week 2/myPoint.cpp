#include <iostream>
using namespace std;

struct Point
{
    int x, y;
    Point()
    {
        //nothing
    }
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    Point operator+(const Point p2)
    {
        Point sum;
        sum.x = this->x + p2.x;
        sum.y = this->y + p2.y;
        return sum;
    }
};

class AwesomePoint
{
private:
    int x, y;

public:
    AwesomePoint()
    {
        //nothing
    }
    AwesomePoint(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    int getX() const
    {
        return x;
    }
    void setX(int x)
    {
        this->x = x;
    }
    int getY() const
    {
        return y;
    }
    void setY(int y)
    {
        this->y = y;
    }
    const AwesomePoint operator+(const Point p)
    {
        AwesomePoint ap;
        ap.setX(this->x + p.x);
        ap.setY(this->y + p.y);
        return ap;
    }
};

ostream &operator<<(ostream &out, const Point p)
{
    out << "(" << p.x << ", " << p.y << ")";
    return out;
}

ostream &operator<<(ostream &out, const AwesomePoint p)
{
    out << "Awesome: " << p.getX() << ", " << p.getY() << endl;
    return out;
}

int main()
{
    Point p1(3, 3), p2(6, 6);
    cout << "p1: " << p1 << "\tp2: " << p2 << endl;
    Point sum = p1 + p2;
    cout << "sum: " << sum << endl;
    AwesomePoint ap = {3, 5};
    cout << ap;
    AwesomePoint ap2 = ap + sum;
    cout << ap2;
    return 0;
}