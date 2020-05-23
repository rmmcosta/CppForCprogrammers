#include <iostream>
using namespace std;

template <class T>
inline T sum(T a, T b)
{
    return a + b;
}

int main()
{
    int a = 6, b = 11;
    double x = 5.5, y = 4.4;
    cout << sum(a, b) << " " << sum(x, y) << endl;
    return 0;
}