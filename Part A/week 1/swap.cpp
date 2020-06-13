//cpp program to swap any
//two values entered by the user

using namespace std;
#include <iostream>

inline void swap(int &first, int &second)
{
    int temp = first;
    first = second;
    second = temp;
}

inline void swap(double &first, double &second)
{
    double temp = first;
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
    swap(firstI, secondI);
    cout << "Result -> " << firstI << ", " << secondI << endl;
    cout << "Now input 2 doubles. First: ";
    cin >> firstD;
    cout << "Second: ";
    cin >> secondD;
    cout << "You entered these 2 doubles: " << firstD << ", " << secondD << endl;
    swap(firstD, secondD);
    cout << "Result -> " << firstD << ", " << secondD << endl;
    return 0;
}