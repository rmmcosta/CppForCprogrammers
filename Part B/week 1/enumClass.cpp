#include <iostream>
using namespace std;

enum class ThreeLog : unsigned
{
    yes = 2,
    maybe = 1,
    no = 3
};

ostream &operator<<(ostream &out, ThreeLog &tl)
{
    switch (tl)
    {
    case ThreeLog::yes:
        out << "value: " << 2 << ", caption: "
            << "yes" << endl;
        break;
    case ThreeLog::maybe:
        out << "value: " << 1 << ", caption: "
            << "maybe" << endl;
        break;
    case ThreeLog::no:
        out << "value: " << 3 << ", caption: "
            << "no" << endl;
        break;
    default:
        out << "value: " << 0 << ", caption: "
            << "invalid" << endl;
        break;
    }
    return out;
}

ThreeLog &operator*(ThreeLog &tl, int i)
{
    int times;
    if (i % 2 == 0)
    {
        times = 2;
    }
    else if (i % 3 == 0)
    {
        times = 3;
    }
    else
    {
        times = 1;
    }
    switch (times)
    {
    case 2:
        tl = ThreeLog::yes;
        break;
    case 1:
        tl = ThreeLog::maybe;
        break;
    default:
        tl = ThreeLog::no;
        break;
    }
    return tl;
}

int main()
{
    ThreeLog tl1 = ThreeLog::maybe;
    cout << tl1 << endl;
    tl1 = tl1 * 2;
    cout << tl1 << endl;
    tl1=ThreeLog::maybe;
    tl1=tl1*3;
    cout << tl1 << endl;
    return 0;
}