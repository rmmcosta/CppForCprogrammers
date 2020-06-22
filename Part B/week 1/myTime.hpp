#include <iostream>
using namespace std;

#ifndef MYTIME_HPP
#define MYTIME_HPP
class MyTime
{
public:
    MyTime(int h, int m = 0, int s = 0) : hours(h), minutes(m), seconds(s){};
    void addHours(int);
    void addMinutes(int);
    void addSeconds(int);
    friend ostream &operator<<(ostream &, const MyTime &);
    MyTime operator+(const MyTime &) const;
    MyTime operator-(const MyTime &) const;
    MyTime operator*(double) const;
    friend MyTime operator*(double, const MyTime &);

private:
    int hours, minutes, seconds;
};
#endif