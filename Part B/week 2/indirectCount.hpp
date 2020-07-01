#include <iostream>
using namespace std;

#ifndef INDIRECT_HPP
#define INDIRECT_HPP

class Indirect
{
public:
    Indirect(const char *);
    Indirect(const Indirect &); //necessary to explicitlty use copy constructor
    ~Indirect();
    friend ostream &operator<<(ostream &out, Indirect &ind);
    static int count;

private:
    char *name;
};
#endif