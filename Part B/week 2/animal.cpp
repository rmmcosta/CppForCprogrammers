#include "animal.hpp"

int Animal::count = 0;

Animal::Animal(string breed, string name, int age)
{
    this->breed = breed;
    this->name = name;
    this->age = age;
    count++;
}

void Animal::walk()
{
    p.incX(1);
    p.incY(1);
}

ostream &operator<<(ostream &out, Animal &a)
{
    cout << a.breed << ", " << a.name << " with " << a.age << " years" << endl;
    return out;
}