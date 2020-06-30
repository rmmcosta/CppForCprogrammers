#include "animal.hpp"

#ifndef DOG_HPP
#define DOG_HPP
class Dog : public Animal
{
public:
    Dog(string breed, string name, int age) : Animal(breed, name, age){};
    void bark();
    void walk();
};
#endif