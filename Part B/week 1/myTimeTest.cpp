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
    MyTime t4(2);
    MyTime t5(1);
    cout << "t4 " << t4 << endl;
    cout << "t5 " << t5 << endl;
    cout << "t4+t5 " << (t4 + t5) << endl;
    t4.addMinutes(50);
    cout << "t4 + 50min -> " << t4 << endl;
    t5.addSeconds(125);
    t5.addHours(5);
    cout << "t5 + 5h + 125seconds -> " << t5 << endl;
    return 0;
}