#include "derivedClass.hpp"
#include <iostream>
using namespace std;

Derived::Derived()
{
    cout << "derived class constructor" << endl;
}

Derived::Derived(int i)
{
    cout << "derived class constructor with i " << i << endl;
}