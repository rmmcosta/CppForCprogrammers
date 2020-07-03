#include "student.hpp"
#include <iostream>

void saySomething(Person&);

int main()
{
    Student s1("Ricardo Costa");
    s1.talk();
    s1.present();
    s1.printGrades();
    s1.addGrade("Algebra", 16);
    s1.printGrades();
    Person p1("Ana Ramos");
    p1.talk();
    p1.present();
    cout << "now passing this objects to the say something method" << endl;
    saySomething(p1);
    saySomething(s1);
    return 0;
}

void saySomething(Person &p)
{
    p.present();
    p.talk();
}