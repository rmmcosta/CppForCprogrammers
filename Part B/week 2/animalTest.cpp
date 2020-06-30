#include "animal.hpp"

int main()
{
    Animal a("Boxer", "Pulguento", 2);
    cout << a;
    Position p = a.getPosition();
    cout << p << endl;
    a.walk();
    p = a.getPosition();
    cout << p << endl;
    return 0;
}