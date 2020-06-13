#include <iostream>
using namespace std;

int main() {
    char *pChar = new char[10]; //heap memory
    for (int i = 0; i < 10; i++)
    {
        pChar[i] = 'A';
    }
    cout << "pchar size" << sizeof(pChar)/sizeof(char) << endl;
    cout << "pchar" << pChar << endl;
    cout << "pchar address" << &pChar << endl;
    delete []pChar; // deallocate array
    cout << "pchar" << pChar << endl;
    cout << "pchar address" << &pChar << endl;
    cout << "pchar size" << sizeof(pChar)/sizeof(char) << endl;
    char cArr[100]; //stack memory
    for (int i = 0; i < 100; i++)
    {
        cArr[i] = 'A';
    }
    cout << "cArr size:" << sizeof(cArr)/sizeof(char) << endl;
    //there's no need for doing the deallocation
    int *p = new int(9);//single element in the heap
    cout << "p:" << *p << endl;
    *p=10;
    cout << "p:" << *p << endl;
    delete p;
    cout << "p:" << *p << endl;
}