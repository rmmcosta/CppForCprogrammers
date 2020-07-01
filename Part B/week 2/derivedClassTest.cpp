#include "derivedClass.hpp"
#include <iostream>
using namespace std;

int main()
{
    cout << "first the derived" << endl;
    Derived d1;
    cout << "then the base" << endl;
    Base b1;
    cout << "derived with int" << endl;
    Derived d2(5);//we need to define a constructor in the derived with this argument list
    cout << "derived with char" << endl;
    Derived d3('A');
    return 0;
}