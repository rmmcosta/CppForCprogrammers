#include "myTime.hpp"

void MyTime::addHours(int h)
{
    hours += h;
}
void MyTime::addMinutes(int m)
{
    //careful with more than 59
    minutes += m;
    hours += minutes / 60;
    minutes %= 60;
}
void MyTime::addSeconds(int s)
{
    //careful with more than 59
    seconds += s;
    addMinutes(seconds / 60);
    seconds %= 60;
}
ostream &operator<<(ostream &out, const MyTime &t)
{
    out << t.hours << "h " << t.minutes << "m " << t.seconds << "s" << endl;
    return out;
}
MyTime MyTime::operator+(const MyTime &t) const
{
    int seconds = hours * 3600 + minutes * 60 + seconds + t.hours * 3600 + t.minutes * 60 + t.seconds;
    int minutes = seconds / 60;
    seconds %= 60;
    int hours = minutes / 60;
    minutes %= 60;
    return MyTime(hours, minutes, seconds);
}
MyTime MyTime::operator-(const MyTime &t) const
{
    int seconds = (hours * 3600 + minutes * 60 + seconds) - (t.hours * 3600 + t.minutes * 60 + t.seconds);
    seconds = abs(seconds);
    int minutes = seconds / 60;
    seconds %= 60;
    int hours = minutes / 60;
    minutes %= 60;
    return MyTime(hours, minutes, seconds);
}
MyTime MyTime::operator*(double n) const
{
    int seconds = hours * 3600 + minutes * 60 + seconds;
    seconds *= n;
    int minutes = seconds / 60;
    seconds %= 60;
    int hours = minutes / 60;
    minutes %= 60;
    return MyTime(hours, minutes, seconds);
}
MyTime operator*(double n, const MyTime &t)
{
    return t*n;
}