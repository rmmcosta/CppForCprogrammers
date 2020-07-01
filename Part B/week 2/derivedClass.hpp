#include "baseClass.hpp"

#ifndef DERIVED_HPP
#define DERIVED_HPP
class Derived : public Base
{
public:
    Derived();
    Derived(int);
    Derived(char c):Base((int)c){};
};
#endif