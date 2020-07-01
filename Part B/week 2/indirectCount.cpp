#include "indirectCount.hpp"
#include <cstring>

int Indirect::count = 0;

Indirect::Indirect(const char *s)
{
    name = new char[strlen(s)];
    strcpy(name, s);
    count++;
}

Indirect::Indirect(const Indirect &ind)
{
    name = new char[strlen(ind.name)];
    strcpy(name, ind.name);
    count++;
}

Indirect::~Indirect()
{
    delete[] name;
    count--;
}

ostream &operator<<(ostream &out, Indirect &ind)
{
    out << "name: " << ind.name << endl;
    return out;
}