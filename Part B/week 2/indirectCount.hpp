#include <iostream>
using namespace std;

#ifndef INDIRECT_HPP
#define INDIRECT_HPP

class Indirect
{
public:
    Indirect();
    Indirect(const char *);
    Indirect(const Indirect &); //necessary to explicitlty use copy constructor
    ~Indirect();
    Indirect &operator=(Indirect &);
    char &operator[](int);
    const char &operator[](int) const; //for read-only objects
    friend ostream &operator<<(ostream &out, Indirect &ind);
    friend ostream &operator<<(ostream &out, const Indirect &ind); //for read-only objects
    static int count;

private:
    char *name;
};
#endif