#include <string>
#include <iostream>
#include "position.hpp"
using namespace std;

#ifndef ANIMAL_HPP
#define ANIMAL_HPP
class Animal
{
protected:
    string name, breed;
    int age;
    Position p;

public:
    Animal(string, string, int);
    virtual void walk();
    Position getPosition() { return p; }
    friend ostream &operator<<(ostream &, Animal &);
    static int count;
};
#endif