#include <iostream>
using namespace std;

int main()
{
    cout << "exception example" << endl;
    try
    {
        cout << "test exception being caught" << endl;
        throw "cenas";
    }
    catch (...)
    {
        cout << "don't abort!" << endl;
    }

    throw "this is a thrown exception";
    return 0;
}