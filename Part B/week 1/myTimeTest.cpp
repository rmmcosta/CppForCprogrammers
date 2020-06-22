#include "myTime.hpp"

int main()
{
    MyTime t1(5, 10, 10);
    cout << t1 << endl;
    t1 = t1 * 2;
    cout << t1 << endl;
    t1 = 2 * t1;
    cout << t1 << endl;
    MyTime t2(3, 50, 50);
    cout << t2 << endl;
    MyTime t3(0);
    t3 = t1 + t2;
    cout << t3 << endl;
    return 0;
}