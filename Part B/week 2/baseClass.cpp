#include "baseClass.hpp"
#include <iostream>
using namespace std;

Base::Base()
{
    cout << "base class constructor" << endl;
}

Base::Base(int i)
{
    cout << "base class constructor with i " << i << endl;
}