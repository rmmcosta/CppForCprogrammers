#include "simple.hpp"
#include <iostream>

int main()
{
    Simple s;
    s.print();
    Simple s1(3, 4);
    s1.print();
    //Simple s2(13.5, 15.6);//this conversion constructor is marked as delete
    //s2.print();
    Simple s3(s1);
    s3.print();
    s1.setX(30);
    s1.setY(40);
    s1.print();
    s3.print();
    std::cout << "move" << std::endl;
    Simple s4(std::move(s1));
    s1.print();
    s4.print();
    s1.setX(300);
    s1.setY(400);
    s1.print();
    s4.print();
    Rational r(55, 66); //by using the Simple::Simple
    r.print();
    return 0;
}