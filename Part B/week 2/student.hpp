#include "person.hpp"
#include <map>

#ifndef STUDENT_HPP
#define STUDENT_HPP
class Student : public Person
{
public:
    Student(string name) : Person(name){};
    ~Student();
    void addGrade(const string, int);
    void printGrades() const;
    void talk() const;

protected:
    map<string, int> grades;
};
#endif