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
    cout << "hours * 3600 + minutes * 60 + seconds -> " << hours * 3600 + minutes * 60 + seconds << endl;
    cout << "t.hours * 3600 + t.minutes * 60 + t.seconds -> " << t.hours * 3600 + t.minutes * 60 + t.seconds << endl;
    int s = hours * 3600 + minutes * 60 + seconds + t.hours * 3600 + t.minutes * 60 + t.seconds;
    cout << "seconds " << s << endl;
    int m = s / 60;
    cout << "minutes " << m << endl;
    s %= 60;
    int h = m / 60;
    m %= 60;
    return MyTime(h, m, s);
}
MyTime MyTime::operator-(const MyTime &t) const
{
    int s= (hours * 3600 + minutes * 60 + seconds) - (t.hours * 3600 + t.minutes * 60 + t.seconds);
    s = abs(s);
    int m = s / 60;
    s%= 60;
    int h = m/ 60;
    m %= 60;
    return MyTime(h, m, s);
}
MyTime MyTime::operator*(double n) const
{
    int s = hours * 3600 + minutes * 60 + seconds;
    s*= n;
    int m = s / 60;
    s %= 60;
    int h = m / 60;
    m %= 60;
    return MyTime(h, m, s);
}
MyTime operator*(double n, const MyTime &t)
{
    return t * n;
}