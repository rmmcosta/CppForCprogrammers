#include <iostream>
using namespace std;

enum Color
{
    kRed,
    kBlue,
    kGreen
};
enum Traffic
{
    kRedT,
    kBlueT,
    kGreenT
}; // can't have the same enum name

enum class cColor
{
    kRed,
    kBlue,
    kGreen
};
enum class cTraffic
{
    kRed,
    kBlue,
    kGreen
};

ostream &operator<<(ostream &out, cColor c)
{
    switch (c)
    {
    case cColor::kRed:
        out << "Red";
        break;
    case cColor::kBlue:
        out << "Blue";
        break;
    case cColor::kGreen:
        out << "Green";
        break;
    default:
        out << "unknown";
        break;
    }
    return out;
}

ostream &operator<<(ostream &out, cTraffic t)
{
    switch (t)
    {
    case cTraffic::kRed:
        out << "Red";
        break;
    case cTraffic::kBlue:
        out << "Blue";
        break;
    case cTraffic::kGreen:
        out << "Green";
        break;
    default:
        out << "unknown";
        break;
    }
    return out;
}

int main()
{
    Color c1 = kRed;
    Traffic t1 = kRedT;
    cColor cc1 = cColor::kRed;
    cTraffic ct1 = cTraffic::kRed;
    cout << "enum color:" << c1 << endl;
    cout << "enum traffic:" << t1 << endl;
    cout << "c1==t1 " << (c1 == (Color)t1) << endl;
    cout << "enum class color:" << cc1 << endl;
    cout << "enum class traffic:" << ct1 << endl;
    cout << "cc1==ct1 " << (cc1 == static_cast<cColor>(ct1)) << endl;
    return 0;
}