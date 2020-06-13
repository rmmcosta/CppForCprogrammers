//cpp program to swap any
//two values entered by the user

using namespace std;
#include <iostream>


template <class T>
inline void mySwap(T &first, T &second)
{
    T temp = first;
    first = second;
    second = temp;
}

int main()
{
    int firstI = 0, secondI = 0;
    double firstD = 0.0, secondD = 0.0;
    cout << "Please input 2 integers. First: ";
    cin >> firstI;
    cout << "Second: ";
    cin >> secondI;
    cout << "You entered these 2 integers: " << firstI << ", " << secondI << endl;
    mySwap(firstI, secondI);
    cout << "Result -> " << firstI << ", " << secondI << endl;
    cout << "Now input 2 doubles. First: ";
    cin >> firstD;
    cout << "Second: ";
    cin >> secondD;
    cout << "You entered these 2 doubles: " << firstD << ", " << secondD << endl;
    mySwap(firstD, secondD);
    cout << "Result -> " << firstD << ", " << secondD << endl;
    return 0;
}