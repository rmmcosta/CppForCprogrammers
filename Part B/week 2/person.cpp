#include "person.hpp"
#include <iostream>

Person::Person(string n)
{
    name=n;
}

Person::~Person()
{
    //do nothing for now
}

void Person::present() const
{
    cout << "My name is " << name << endl;
}

void Person::talk() const
{
    cout << "I can talk because I'm a person" << endl;
}