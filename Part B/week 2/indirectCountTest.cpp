#include "indirectCount.hpp"

void callme1(Indirect&); //by reference
void callme2(Indirect); //by value

int main()
{
    Indirect *i1 = new Indirect("xpto");
    cout << *i1;
    Indirect *i2 = new Indirect("coiso");
    cout << *i2;
    Indirect *i3 = new Indirect("etal");
    cout << *i3;
    cout << "total:" << Indirect::count << endl;
    callme1(*i3);
    cout << "total:" << Indirect::count << endl;
    callme2(*i2);
    cout << "total:" << Indirect::count << endl;
    cout << *i2;
    delete i3;
    delete i2;
    delete i1;
    cout << "total:" << Indirect::count << endl;
    return 0;
}

void callme1(Indirect &ind)
{
    cout << "inside callme1 " << ind;
    cout << "inside callme1, total " << Indirect::count << endl;
}

void callme2(Indirect ind)
{
    cout << "inside callme2 " << ind;
    cout << "inside callme2, total " << Indirect::count << endl;
}