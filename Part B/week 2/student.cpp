#include "student.hpp"
#include <iostream>

void Student::printGrades() const
{
    if(grades.size()==0)
    {
        cout << "You don't have grades yet" << endl;
        return;
    }
    for (auto it = grades.begin(); it != grades.end(); it++)
    {
        cout << it->first << " : " << it->second << endl;
    }
}

void Student::addGrade(const string discipline, int grade)
{
    grades.insert(pair<string, int>(discipline, grade));
}

void Student::talk() const
{
    cout << "I can talk very well because I'm a student" << endl;
}

Student::~Student()
{
    //do nothing for now
}