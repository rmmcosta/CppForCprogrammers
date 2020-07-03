#include <string>
using namespace std;

#ifndef PERSON_HPP
#define PERSON_HPP
class Person
{
    public:
        Person(string);
        ~Person();
        virtual void talk() const;
        void present() const;
    protected:
        string name;
};
#endif