#include "dog.hpp"

void Dog::bark() const
{
    cout << name << " is barking" << endl;
}

void Dog::walk()
{
    p.decX(1);
    p.decY(1);
}