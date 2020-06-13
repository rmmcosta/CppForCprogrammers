#include <iostream>
using namespace std;

enum Day
{
    MON,
    TUE,
    WED,
    THU,
    FRI,
    SAT,
    SUN
};

inline Day operator++(Day &day)
{

    return day = static_cast<Day>((day + 1) % 7);
}

/* inline Day operator++(Day)
{
  Day tmp(*this);
  operator++(); // prefix-increment this instance
  return tmp;   // return value before increment
} */

ostream &operator<<(ostream &out, const Day &day)
{
    switch (day)
    {
    case MON:
        out << "MON";
        break;
    case TUE:
        out << "TUE";
        break;
    case WED:
        out << "WED";
        break;
    case THU:
        out << "THU";
        break;
    case FRI:
        out << "FRI";
        break;
    case SAT:
        out << "SAT";
        break;
    case SUN:
        out << "SUN";
        break;
    default:
        break;
    }
    return out;
}

int main()
{
    Day d = MON;
    for (int i = 0; i < 14; i++)
    {
        cout << d << endl;
        ++d;
    }
}