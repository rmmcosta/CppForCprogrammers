#include <iostream>
using namespace std;

enum Color
{
    WHITE,
    YELLOW,
    BLACK,
    RED,
    BLUE,
    ORANGE
};

class Fruit
{
private:
    Color _color;

public:
    Fruit(Color color)
    {
        this->_color = color;
    }
    void fall()
    {
        cout << "I'm falling from the tree" << endl;
    }
    void setColor(Color color)
    {
        this->_color = color;
    }
    Color getColor()
    {
        return this->_color;
    }
};

class Banana : Fruit
{
public:
    Banana() : Fruit(YELLOW)
    {
    }
    void fall()
    {
        cout << "The banana is falling from the tree..." << endl;
    }
    Color getColor()
    {
        return Fruit::getColor();
    }
};

int main()
{
    Fruit f = *new Fruit(ORANGE);
    f.fall();
    cout << ":" << f.getColor() << endl;
    Banana b = *new Banana();
    b.fall();
    cout << ":" << b.getColor() << endl;
    return 0;
}