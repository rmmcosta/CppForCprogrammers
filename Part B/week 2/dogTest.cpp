#include "dog.hpp"

int main()
{
    Dog d1("Pastor Alemão", "Jack", 4);
    d1.bark();
    cout << d1;
    cout << d1.count << endl;
    Dog d2("Shi poo", "Freddy", 3);
    cout << d2;
    d2.bark();
    cout << d2.count << endl;
    Position p2 = d2.getPosition();
    cout << p2 << endl;
    d2.walk();
    p2 = d2.getPosition();
    cout << p2 << endl;
    return 0;
}