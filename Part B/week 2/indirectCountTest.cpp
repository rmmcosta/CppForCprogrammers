#include "indirectCount.hpp"

void callme1(Indirect &); //by reference
void callme2(Indirect);   //by value

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
    Indirect i4 = *i3;
    cout << "total:" << Indirect::count << endl;
    cout << i4;
    delete i3;
    delete i2;
    delete i1;
    cout << "total:" << Indirect::count << endl;
    cout << i4;
    {
        Indirect ind1("coiso e tal e cenas");
        cout << ind1;
        cout << "total:" << Indirect::count << endl;
        Indirect ind2(ind1);
        cout << ind2;
        cout << "total:" << Indirect::count << endl;
    }
    cout << "total:" << Indirect::count << endl;
    Indirect ind3, ind4, ind5;
    cout << "inds: ";
    cout << ind3 << ind4 << ind5;
    cout << "total:" << Indirect::count << endl;
    {
        Indirect indM("master");
        ind3 = ind4 = ind5 = indM;
    }
    cout << "inds: ";
    cout << ind3 << ind4 << ind5;
    cout << "total:" << Indirect::count << endl;
    cout << ind5[0] << endl;
    ind5[0] = 'M';
    cout << ind5;
    const Indirect indC("read-only");
    cout << indC;
    cout << indC[4] << endl;
    //indC[4] = '+';//not allowed because it's a read-only object
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