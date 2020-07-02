#include "indirectCount.hpp"
#include <cstring>

int Indirect::count = 0;

Indirect::Indirect()
{
    name = new char[0];
    name[0] = '\0';
    count++;
}

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

Indirect &Indirect::operator=(Indirect &ind)
{
    if (this == &ind)
        return *this;
    delete[] name;
    this->name = new char[strlen(ind.name)];
    strcpy(this->name, ind.name);
    return *this;
}

char &Indirect::operator[](int i)
{
    return this->name[i];
}

const char &Indirect::operator[](int i) const
{
    return this->name[i];
}

ostream &operator<<(ostream &out, Indirect &ind)
{
    out << "name: " << ind.name << endl;
    return out;
}

ostream &operator<<(ostream &out, const Indirect &ind)
{
    out << "name: " << ind.name << endl;
    return out;
}